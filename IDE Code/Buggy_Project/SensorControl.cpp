/**
    SensorControl.cpp
    Purpose: This is class encapsulates all the grid sensor and controls 
    the motors based on their response

    @author Roy Miles
    @version 1.0 11/12/2016
*/

#include "SensorControl.h"

const byte SENSOR_MUX = 9;     // Output pin to control the MUX

colourState SensorControl::currentColourState = BLACK_WHITE; // Will alternate at start of movement init
crossOrLine SensorControl::currentPositionState = LINE;

/**
 * Constructor
 * Create instances of the IR sensors
 */
SensorControl::SensorControl(Movement *m)
{
  Serial.println("Sensor control instance");
  this->m = m;

  // These sensors are alligned with the wheels of the buggy
  sgs = new SideGridSensor();

  // These sensors are used as alternatives to the RGB sensors (less complex)
  fgs = new FrontGridSensor();

  pinMode(REED_SWITCH1, INPUT);  
  pinMode(REED_SWITCH2, INPUT);  
  
}

SensorControl::~SensorControl()
{
}

void SensorControl::calibrate(){
  fgs->calibrate();
  sgs->calibrate();
}

/**
 * Read in the maximum and minimum readings from calibrations
 * The average of these two values are used as the thresholds
 * for WHITE and BLACK
 * 
 * If the threshold is outside the typical expected range, it is
 * assumed that the calibration was not reliable and it will be 
 * hard limited to an upper and lower bound
 */
void SensorControl::postCalibration(){
  fgs->postCalibration();
  sgs->postCalibration();

  unsigned int threshold;

  /*
   * Calculate the thresholds using the calibration data
   */
  threshold = limitThreshold((sgs->getMinimum(0) + sgs->getMaximum(0)) / 2);
  sideSensorThreshold[0] = threshold; // Maximum value of 1800 
  Serial.print(F("Side left threshold: "));
  Serial.println(sideSensorThreshold[0]);
  
  threshold = limitThreshold((sgs->getMinimum(1) + sgs->getMaximum(1)) / 2);
  sideSensorThreshold[1] = threshold; // Maximum value of 1800 
  Serial.print(F("Side right threshold: "));
  Serial.println(sideSensorThreshold[1]);

  threshold = limitThreshold((fgs->getMinimum(0) + sgs->getMaximum(0)) / 2);
  frontSensorThreshold[0] = threshold; // Maximum value of 1800 
  Serial.print(F("Front left threshold: "));
  Serial.println(frontSensorThreshold[0]);
  
  threshold = limitThreshold((fgs->getMinimum(1) + sgs->getMaximum(1)) / 2);
  frontSensorThreshold[1] = threshold; // Maximum value of 1800 
  Serial.print(F("Front right threshold: "));
  Serial.println(frontSensorThreshold[1]);
  
  threshold = limitThreshold((fgs->getMinimum(2) + sgs->getMaximum(2)) / 2);
  frontSensorThreshold[2] = threshold; // Maximum value of 1800 
  Serial.print(F("Front right backup threshold: "));
  Serial.println(frontSensorThreshold[2]);
}

/**
 * Limit the threshold value between 1000-1800
 * @return the threshold hard limited between the two values
 */
unsigned int SensorControl::limitThreshold(unsigned int threshold){
  if(threshold < THRESHOLD_MIN){ 
    return THRESHOLD_MIN; 
  }else if(threshold > THRESHOLD_MAX){ 
    return THRESHOLD_MAX; 
  }else{
    return threshold;
  }
}

/**
 * Read the IR sensor values and store them in an array as enums (colours)
 */
void SensorControl::getSideSensorColours(){
  sgs->readSideSensors(); // Make sure the latest values are measured

  sideSensorColours[0] = convertSideSensorValueToColour(sgs->sideSensorValues[0], 0);
  sideSensorColours[1] = convertSideSensorValueToColour(sgs->sideSensorValues[1], 1);
}

void SensorControl::getFrontSensorColours(){
  fgs->readFrontSensors(); // Make sure the latest values are measured

  frontSensorColours[0] = convertFrontSensorValueToColour(fgs->frontSensorValues[0], 0);
  frontSensorColours[1] = convertFrontSensorValueToColour(fgs->frontSensorValues[1], 1);
  frontSensorColours[2] = convertFrontSensorValueToColour(fgs->frontSensorValues[2], 2);
}

/*
 * Used to convert the simple sensor values to a WHITE/BLACK colour
 * Note: The thresholds are dependant on the distance of the IR sensors to the ground
 * Note: This is used for the 2 side sensors
 * 
 * @param value, the reading from the sensor
 * @param index, determines which sensor threshold to use as each sensor will
 * have a different threshold from the calibration stage
 * @return a colour enum for the reading
 */
colour SensorControl::convertSideSensorValueToColour(unsigned int value, unsigned int index){
  if(value < sideSensorThreshold[index]){
    return WHITE;
  }else{
    return BLACK;
  }
}

/*
 * Used to convert the simple sensor values to a WHITE/BLACK colour
 * Note: The thresholds are dependant on the distance of the IR sensors to the ground
 * Note: This is used for the 3 front sensors.
 * 
 * @param value, the reading from the sensor
 * @param index, determines which sensor threshold to use as each sensor will
 * have a different threshold from the calibration stage
 * @return a colour enum for the reading
 */
colour SensorControl::convertFrontSensorValueToColour(unsigned int value, unsigned int index){
  if(value < frontSensorThreshold[index]){
    return WHITE;
  }else{
    return BLACK;
  }
}

/**
 * This function just reads in the IR sensors and prints relevant debug information
 */
void SensorControl::debug(){
  Serial.println(F("DEBUG >>>"));
  Serial.println(F(">>> Front Sensors"));
  Serial.print(F("Front threshold: "));
  Serial.print(frontSensorThreshold[0]);
  Serial.print(F(", "));
  Serial.println(frontSensorThreshold[1]);
  
  getFrontSensorColours();
  Serial.print(F("FRONT LEFT: "));
  Serial.print(colourToString(frontSensorColours[0]));
  Serial.print(F(" "));
  Serial.println(fgs->frontSensorValues[0]);
  
  Serial.print(F("FRONT RIGHT: "));
  Serial.print(colourToString(frontSensorColours[1]));
  Serial.print(F(" "));
  Serial.println(fgs->frontSensorValues[1]);
  
  Serial.print(F("FRONT BACKUP: "));
  Serial.print(colourToString(frontSensorColours[2]));
  Serial.print(F(" "));
  Serial.println(fgs->frontSensorValues[2]);
  
  Serial.println(F(">>> Side Sensors"));
  Serial.print(F("Side threshold: "));
  Serial.print(sideSensorThreshold[0]);
  Serial.print(F(", "));
  Serial.print(sideSensorThreshold[1]);
  Serial.print(F(", "));
  Serial.println(sideSensorThreshold[2]);
  
  getSideSensorColours();
  Serial.print(F("SIDE LEFT: "));
  Serial.print(colourToString(sideSensorColours[0]));
  Serial.print(F(" "));
  Serial.println(sgs->sideSensorValues[0]);
  
  Serial.print(F("SIDE RIGHT: "));
  Serial.print(colourToString(sideSensorColours[1]));
  Serial.print(F(" "));
  Serial.println(sgs->sideSensorValues[1]);
  
  Serial.println(F("END DEBUG >>>"));
}

/**
 * Get the initial readings prior to movement and calculate the expected grid sqaures after movement
 */
bool wiggleLeft = 0; // Right = 0, Left = 1
void SensorControl::movementInit(movements pm, movements cm){  
//  Serial.print(F("Previous movement: "));
//  Serial.println(m->getMovement(pm));
//  Serial.print(F("Current movement: "));
//  Serial.println(m->getMovement(cm));

  /*
   * Simple Front Sensors (alternative to the RGB Sensors)
   */
  getFrontSensorColours();  
  initialSensorReading_left         = frontSensorColours[0];
  initialSensorReading_right        = frontSensorColours[1];
  initialSensorReading_rightBackup  = frontSensorColours[2];

  /*
   * Side Sensors
   */
  getSideSensorColours();
  initialSideSensorReading_left  = sideSensorColours[0];
  initialSideSensorReading_right = sideSensorColours[1];

  // If the front sensors are initially different, wiggle the buggy
  if(initialSensorReading_left == initialSensorReading_right /*&& (cm != TURNING_RIGHT || cm != TURNING_LEFT)*/ ){
    if(pm == TURNING_RIGHT){
      wiggleLeft = 1;
    }
    wiggleBuggy(pm); // Wiggle the buggy until the front sensors are different
  }

  // Get the buggy position state CROSS or LINE and the start grid colours
  getPositionState();
  
}

/**
 * Wiggle the buggy left and right (for an incrementing amount of time) until the front sensors have different values
 * This function will keep calling itself untill the buggy is alligned with the grid line
 */
const unsigned int initialWiggleDuration = 20;
const unsigned int wiggleDurationIncrement = 20;

unsigned int wiggleDelay = initialWiggleDuration; // 100ms = 0.1s
const unsigned int postWiggleDelay = 100; // 1s
bool SensorControl::wiggleBuggy(movements pm){
  Communication::setCurState(SLAVE_WIGGLING);

//  // example
//  getFrontSensorColours();  
//  initialSensorReading_left           = frontSensorColours[0];
//  initialSensorReading_right          = frontSensorColours[1];
//  initialSensorReading_rightBackup    = frontSensorColours[2];
//  
//  if(!finishCondition){
//    if(finishedWiggleTurn == 1){
//      finishedWiggleTurn = 0;
//      if(wiggleLeft == 1){
//        m->turnLeft();
//        wiggleLeft = 0;
//      }else{
//        m->turnRight();
//        wiggleLeft = 1;
//      }
//
//      Movement::wiggleDelay += wiggleDurationIncrement; // Increase the wiggle duration by 0.05s
//    }
//  }else{
//    Serial.println(F("Finished wiggling"));
//    Movement::isWiggling = false;
//    Movement::wiggleDelay = initialWiggleDuration; // Reset wiggle delay and finish
//  }
//  delay(50);
//  // end example
  
  Movement::isWiggling = true;
  Serial.println(F("Wiggling buggy"));
  if(wiggleLeft == 1){
    // Turn Left
    m->turnLeft();
    delay(wiggleDelay);
    Movement::stopMovement();
    delay(postWiggleDelay); // Allow things to settle
    wiggleLeft = 0; // Toggle
  }else{
    // Turn right
    m->turnRight();
    delay(wiggleDelay);
    Movement::stopMovement();
    delay(postWiggleDelay); // Allow things to settle
    wiggleLeft = 1; // Toggle
  }

  /*
   * Check if the front sensors have now changed. If not rerun the function
   */
  getFrontSensorColours();  
  initialSensorReading_left           = frontSensorColours[0];
  initialSensorReading_right          = frontSensorColours[1];
  initialSensorReading_rightBackup    = frontSensorColours[2];

  bool finishCondition = (initialSensorReading_left != initialSensorReading_right);

  if(!finishCondition){
    if(wiggleLeft == 0){
      wiggleDelay += wiggleDurationIncrement; // Increase the wiggle duration by 0.05s
    }
    return wiggleBuggy(pm); // Wiggle buggy in opposite direction
  }else{
    Serial.println(F("Finished wiggling"));
    Movement::isWiggling = false;
    wiggleDelay = initialWiggleDuration; // Reset wiggle delay and finish

    Communication::setCurState(SLAVE_FINISHED_WIGGLING);
    return true;
  }
}

bool leftReedSwitch, middleReedSwitch;
const unsigned int dockAdjustmentTime = 100; // 500ms = 0.5s
bool isLastAdjustingDockingLeft = true;
bool SensorControl::adjustDockingPosition(){
  int reedSwitch1 = digitalRead(REED_SWITCH1);
  int reedSwitch2 = digitalRead(REED_SWITCH2);

  Serial.print("Reed switch values: ");
  Serial.print(reedSwitch1);
  Serial.print(", ");
  Serial.print(reedSwitch2);
  Serial.println();

  if(reedSwitch1==LOW && reedSwitch2==LOW){
    // Undocked
    Serial.println("Undocked!");
    // The buggy will probably need to rotate in the same direction it was just rotating

    // At the moment, choose right
    if(isLastAdjustingDockingLeft == true){
      m->turnLeft();
    }else{
      m->turnRight();
    }
    delay(dockAdjustmentTime);
    Movement::stopMovement();
    delay(dockAdjustmentTime);

    isLastAdjustingDockingLeft = true;

    return false;
    
  }else if(reedSwitch1==LOW && reedSwitch2==HIGH){
    // Too far left
    Serial.println("Too far LEFT of target");
    m->turnRight();
    delay(dockAdjustmentTime);
    Movement::stopMovement();
    delay(dockAdjustmentTime);

    isLastAdjustingDockingLeft = false;

    return false;
    
  }else if(reedSwitch1==HIGH && reedSwitch2==LOW){
    // Too far right
    Serial.println("Too far RIGHT of target");
    m->turnLeft();
    delay(dockAdjustmentTime);
    Movement::stopMovement();
    delay(dockAdjustmentTime);

    isLastAdjustingDockingLeft = true;

    return false;
    
  }else if(reedSwitch1==HIGH && reedSwitch2==HIGH){
    // Docked
    Serial.println("Docked!");

//    if(isLastAdjustingDockingLeft == true){
//      m->turnLeft();
//    }else{
//      m->turnRight();
//    }

    //delay(500);
    //Movement::stopMovement();    
    
    return true;
  }
  
}

/**
 * Check if the colour is valid
 */
bool SensorControl::isValidColour(colour c){
  if(c == WHITE || c == BLACK){
    return true;
  }else{
    return false;
  }
}

/**
 * This should be called at the start of the movement sequence
 * Get the current position of the buggy WHITE_BLACK | BLACK_WHITE
 */
void SensorControl::getStartPosition(){
  getSideSensorColours();
  initialSideSensorReading_left   = sideSensorColours[0];
  initialSideSensorReading_right  = sideSensorColours[1];

  getFrontSensorColours();  
  initialSensorReading_left           = frontSensorColours[0];
  initialSensorReading_right          = frontSensorColours[1]; 
  initialSensorReading_rightBackup    = frontSensorColours[2];

  /*
   * Get the colour state
   */
  if(initialSideSensorReading_left == WHITE && initialSideSensorReading_right == BLACK){
      Serial.println(F("Start colour state = WHITE_BLACK"));
      currentColourState = WHITE_BLACK; 
  }else if(initialSideSensorReading_left == BLACK && initialSideSensorReading_right == WHITE){
      Serial.println(F("Start colour state = BLACK_WHITE"));
      currentColourState = BLACK_WHITE; 
  }else{
    Serial.println(F("Side sensors same. Halting."));
    while(true){
      // Flash the LEDs as a warning
      digitalWrite(A3, LOW);
      digitalWrite(A4, LOW);
      digitalWrite(A5, LOW);
      delay(100);
      digitalWrite(A3, HIGH);
      digitalWrite(A4, HIGH);
      digitalWrite(A5, HIGH);
      delay(100);
      ; // Halting
    }
  }

  getPositionState();  
}

/**
 * This function simulates the LUT to enumerate all
 * the possible colour combinations corresponding
 * to the expected position
 */
void SensorControl::getPositionState(){
  /* 
   * Get the position state 
   */

  /*
   * Calculate the state number from the colours
   */
  this->positionState = (colourToNumber(initialSensorReading_left) * 8) + (colourToNumber(initialSensorReading_right) * 4) + (colourToNumber(initialSideSensorReading_left) * 2) + (colourToNumber(initialSideSensorReading_right) * 1);

  /*
   * See Notes
   */
  switch(this->positionState){
    case 4: // 0100
      // Front sensors read WHITE_BLACK and the back sensors are on WHITE. CROSS. Deviating left
      // EDIT: line deviating right
      Serial.println(F("STATE 4 - WHITE_BLACK - CROSS"));
      //--Serial.println(F("Starting on a cross, deviating left with front sensors on WHITE_BLACK and back sensors on WHITE"));
      //--Serial.println(F("Starting on a line, deviating right with front sensors on WHITE_BLACK and back sensors on WHITE"));
//      initialSideSensorReading_left  = BLACK;
//      initialSideSensorReading_right = WHITE;
//      currentColourState = BLACK_WHITE;
//      currentPositionState = CROSS;

      initialSideSensorReading_left  = WHITE;
      initialSideSensorReading_right = BLACK;
      currentColourState = WHITE_BLACK;
      currentPositionState = LINE;
      break;

    case 5: // 0101
      // Ideal line. WHITE_BLACK
      Serial.println(F("STATE 5 - WHITE_BLACK - LINE"));
      //--Serial.println(F("Ideal line WHITE_BLACK"));
      initialSideSensorReading_left  = WHITE;
      initialSideSensorReading_right = BLACK;
      currentColourState = WHITE_BLACK;
      currentPositionState = LINE;
      break;

    case 6: // 0110
      // Ideal cross. Front WHITE_BLACK, Back BLACK_WHITE
      Serial.println(F("STATE 6 - BLACK_WHITE - CROSS"));
      //--Serial.println(F("Ideal cross with front sensors on WHITE_BLACK and back sensors on BLACK_WHITE"));
      initialSideSensorReading_left  = BLACK;
      initialSideSensorReading_right = WHITE;
      currentColourState = BLACK_WHITE;
      currentPositionState = CROSS;
      break;

    case 7: // 0111
      // Front sensors read WHITE_BLACK and the back sensors are on BLACK. CROSS. Deviating right
      // EDIT: LINE deviating left
      Serial.println(F("STATE 7 - WHITE_BLACK - LINE"));
      //Serial.println(F("Starting on a cross, deviating right with front sensors on WHITE_BLACK and back sensors on BLACK"));
      //--Serial.println(F("Line deviating left with front sensors on WHITE_BLACK and back sensors on BLACK"));
//      initialSideSensorReading_left  = BLACK;
//      initialSideSensorReading_right = WHITE;
//      currentColourState = BLACK_WHITE;
//      currentPositionState = CROSS;

      initialSideSensorReading_left  = WHITE;
      initialSideSensorReading_right = BLACK;
      currentColourState = WHITE_BLACK;
      currentPositionState = LINE;
      break;

    case 8: // 1000
      // Front sensors read BLACK_WHITE and the back sensors are on WHITE. CROSS. Deviating right
      // EDIT: line deviating left
      Serial.println(F("STATE 8 - BLACK_WHITE - LINE"));
      //Serial.println(F("Starting on a cross, deviating right with front sensors on BLACK_WHITE and back sensors on WHITE"));
      //--Serial.println(F("Starting on a line, deviating left with front sensors on BLACK_WHITE and back sensors on WHITE"));
//      initialSideSensorReading_left  = WHITE;
//      initialSideSensorReading_right = BLACK;
//      currentColourState = WHITE_BLACK;
//      currentPositionState = CROSS;

      initialSideSensorReading_left  = BLACK;
      initialSideSensorReading_right = WHITE;
      currentColourState = BLACK_WHITE;
      currentPositionState = LINE;
      break;

    case 9: // 1001
      // Ideal cross. Front BLACK_WHITE, Back WHITE_BLACK
      Serial.println(F("STATE 9 - WHITE_BLACK - CROSS"));
      //--Serial.println(F("Ideal cross with front sensors on BLACK_WHITE and back sensors on WHITE_BLACK"));
      initialSideSensorReading_left  = WHITE;
      initialSideSensorReading_right = BLACK;
      currentColourState = WHITE_BLACK;
      currentPositionState = CROSS;
      break;

    case 10: // 1010
      // Ideal line. BLACK_WHITE
      Serial.println(F("STATE 10 - BLACK_WHITE - LINE"));
      //--Serial.println(F("Ideal line BLACK_WHITE"));
      initialSideSensorReading_left  = BLACK;
      initialSideSensorReading_right = WHITE;
      currentColourState = BLACK_WHITE;
      currentPositionState = LINE;
      break;

    case 11: // 1011
      // Front sensors read BLACK_WHITE and the back sensors are on BLACK. CROSS. Deviating left
      // EDIT: line deviatinh right
      Serial.println(F("STATE 11 - BLACK_WHITE - LINE"));
      //Serial.println(F("Starting on a cross, deviating left with front sensors on BLACK_WHITE and back sensors on BLACK"));
      //--Serial.println(F("Starting on a line, deviating right with front sensors on BLACK_WHITE and back sensors on BLACK"));
//      initialSideSensorReading_left  = WHITE;
//      initialSideSensorReading_right = BLACK;
//      currentColourState = WHITE_BLACK;
//      currentPositionState = CROSS;

      initialSideSensorReading_left  = BLACK;
      initialSideSensorReading_right = WHITE;
      currentColourState = BLACK_WHITE;
      currentPositionState = LINE;
      break;

    default:
      Serial.println(F("STATE 0-3 or 12-15"));
      //--Serial.println(F("Front sensors have the same value"));
      Serial.println(F("Unknown position state. Halting..."));
//      while(true){
//        ; // Halt
//      }
  }

}

/*
 * Used to convert a colour to a binary value. For the LUT
 */
unsigned int SensorControl::colourToNumber(colour c){
  if(c == WHITE){
    return 0;
  }else{
    return 1;
  }
}

/**
 * Read from the IR RGB colour sensors and adjust the motor controls to compensate
 * Read from the side sensor to determine if movement has finished
 */
bool left_changed, right_changed, right_backup_changed, sideLeft_changed, sideRight_changed;
bool frontSensorsFlipped = false; 

enum deviatingState {NONE, LEFT_NOT_CHANGED, RIGHT_NOT_CHANGED, CHANGED};
static deviatingState currentDeviatingState = NONE;

// Flags that get set to true whenever a transition has occured and maintain this value for the full movement
bool frontRightFlag = false, frontLeftFlag = false, sideRightFlag = false, sideLeftFlag = false;
byte frontRightCount = 0, frontLeftCount = 0, sideRightCount = 0, sideLeftCount = 0;

bool finishCondition;

/**
 * Read the IR sensors and determine if they have changed and how many times they have changed
 * - Compensate accordingly
 * - Check if the movement has finished
 */
void SensorControl::motorCorrection(){
  
  /*
   * Front sensors
   */
  getFrontSensorColours();
  left_changed          = (initialSensorReading_left  != frontSensorColours[0]);
  right_changed         = (initialSensorReading_right != frontSensorColours[1]);  
  right_backup_changed  = (initialSensorReading_rightBackup != frontSensorColours[2]);

  /*
   * Side sensors
   */
  getSideSensorColours();
  sideLeft_changed  = (initialSideSensorReading_left  != sideSensorColours[0]);
  sideRight_changed = (initialSideSensorReading_right != sideSensorColours[1]); 

  /*
   * Count the transitions using the flag toggles
   */
  checkTransitions();

  
  switch(Movement::currentMovement){

    // Forward and backwards use the same logic
    case FORWARD:
    case BACKWARDS:
    
      // Front sensors moved onto next square, so flip the polarity
      if(frontSensorsFlipped == false && left_changed && right_changed /*&& right_backup_changed*/){
        Serial.println("Front sensors flipped");
        frontSensorsFlipped = true;
        if(initialSensorReading_left == WHITE){
          initialSensorReading_left = BLACK;
        }else{
          initialSensorReading_left = WHITE;
        }
    
        if(initialSensorReading_right == WHITE){
          initialSensorReading_right = BLACK;
        }else{
          initialSensorReading_right = WHITE;
        }    
      }

      /*
       * The IR sensors should see the same colour for all movement
       *  Determine whether the sensors are now reading different values
       */  
  
      // Left sensor has changed but right sensor has not
      //if(right_changed && !left_changed && currentDeviatingState != RIGHT_NOT_CHANGED){
      bool compensateCondition;
      if(Movement::currentMovement == FORWARD){
        compensateCondition = (frontSensorColours[0] == frontSensorColours[1] && frontSensorColours[0] != frontSensorColours[2])
                                && !(frontSensorColours[0]==initialSensorReading_left /*&& frontSensorsFlipped==false*/);
      }else{
        // Backwards
        compensateCondition = (frontSensorColours[0] == frontSensorColours[1] && frontSensorColours[0] != frontSensorColours[2]);
      }
      if(compensateCondition // front right BACKUP sensor is different to the other two sensors
          /*&& currentDeviatingState != RIGHT_NOT_CHANGED*/ ){
        // Need to turn slightly to the RIGHT to compensate
        delay(50); // To allow for misalignment of front sensors eg one sensor sees next grid first

//        if(currentDeviatingState = NONE){
//          currentDeviatingState = LEFT_NOT_CHANGED;
//        }
//        
//        // As soon as the front sensors are different
//        if(frontSensorColours[0] != frontSensorColours[1]){
//          currentDeviatingState = CHANGED;
//        }
  
        //Serial.println("Deviating to the LEFT. Attempting to compensate... Right changed and left has not");
        if(Movement::currentMovement == FORWARD){

          Movement::currentMovementCompensation = COMPENSATING_RIGHT;
          
        }else if(Movement::currentMovement == BACKWARDS){
          /*
           * Opposite polarity for going backwards
           */
          Movement::currentMovementCompensation = COMPENSATING_LEFT;
           
        }
        
      // Right sensor has changed but left sensor has not      
      //}else if(left_changed && !right_changed && currentDeviatingState != LEFT_NOT_CHANGED){
      }else if(frontSensorColours[0] ==  frontSensorColours[1] && frontSensorColours[0] == frontSensorColours[2] 
         /*&& currentDeviatingState != LEFT_NOT_CHANGED*/){
        // Need to turn slightly to the LEFT to compensate
        delay(50); // To allow for misalignment of front sensors eg one sensor sees next grid first

//        if(currentDeviatingState = NONE){
//          currentDeviatingState = RIGHT_NOT_CHANGED;
//        }
//
//        // As soon as the front sensors are different
//        if(frontSensorColours[0] != frontSensorColours[1]){
//          currentDeviatingState = CHANGED;
//        }
  
        //Serial.println("Deviating to the RIGHT. Attempting to compensate... Left changed and right has not");
        if(Movement::currentMovement == FORWARD){
          
          Movement::currentMovementCompensation = COMPENSATING_LEFT;
  
        }else if(Movement::currentMovement == BACKWARDS){
          /*
           * Opposite polarity for going backwards
           */
           Movement::currentMovementCompensation = COMPENSATING_RIGHT;
          
        }
  
      }else{
        // On track, so keep both motors enabled
        Movement::currentMovementCompensation = ON_TRACK;
        //currentDeviatingState = NONE;
      }

      Serial.print("Movement state: ");
      Serial.println(Movement::movementStateToString(Movement::currentMovementCompensation));

      /*
       * If both the wheel sensors have changed
       * Finished movement!
       */
      if(sideLeft_changed && sideRight_changed){
        consecutiveCollisions = 0; // Movement did not end in a collision
        toggleColourState();
        frontSensorsFlipped = false; // Reset
        Movement::stopMovement();
        resetFlagsAndCounts();     
        Communication::setCurState(SLAVE_STOPPED);
      }
      
      break;

    case TURNING_LEFT:
      /* 
       * Stop movement when LEFT sensor has changed cell
       */

      Movement::currentMovementCompensation = ON_TRACK; // Dont compensate for turns
      getSideSensorColours();
      sideLeft_changed  = (initialSideSensorReading_left  != sideSensorColours[0]);
      sideRight_changed = (initialSideSensorReading_right != sideSensorColours[1]);   

      /*
       * FINISHING CONDITIONS
       * If on a cross (ideal situation) just check for the front right sensor to change
       * If on a line, check if the back right sensor has changed twice
       */

      finishCondition = false;
      if(positionState == 5 || positionState == 10){
        // Ideal LINE. Only the back RIGHT sensor needs to change
        Serial.println("ERROR: SHOULD NOT START TURNS ON LINES?");
        //finishCondition = sideRight_changed;
        finishCondition = (sideRightCount > 0);
      }

      if(positionState == 6 || positionState == 9){
        // Ideal CROSS. Only the front RIGHT and back RIGHT sensors needs to change
        //finishCondition = (sideLeft_changed && sideLeft_changed);
        finishCondition = ((sideLeftCount > 0 && sideRightCount > 0) || sideRightCount == 2);
        
      }      

      if(positionState == 4 || positionState == 11){
        // CROSS deviating left
        //finishCondition = left_changed;
        Serial.println(F("ERROR: SHOULD OF WIGGLED BEFORE"));
        finishCondition = (frontLeftCount > 0);
      }  
 
      if(positionState == 7 || positionState == 8){
        // CROSS deviating right
        //finishCondition = left_changed;
        Serial.println(F("ERROR: SHOULD OF WIGGLED BEFORE"));
        finishCondition = (frontLeftCount > 0);
      }      

      // Trying new tings
      // finishCondition = (frontLeftCount > 0);
       
      if(finishCondition){
          consecutiveCollisions = 0; // Movement did not end in a collision
          toggleColourState();
          Movement::stopMovement();
          resetFlagsAndCounts();       
          Communication::setCurState(SLAVE_STOPPED);
      }      
      
      break;

    
    case TURNING_RIGHT:
      /* 
       * Stop movement when RIGHT sensor has changed cell
       */

      Movement::currentMovementCompensation = ON_TRACK; // Dont compensate for turns
      getSideSensorColours();
      sideLeft_changed  = (initialSideSensorReading_left  != sideSensorColours[0]);
      sideRight_changed = (initialSideSensorReading_right != sideSensorColours[1]);        

      /*
       * FINISHING CONDITIONS
       * If on a cross (ideal situation) just check for the front right sensor to change
       * If on a line, check if the back right sensor has changed twice
       */
      finishCondition = false;
      if(positionState == 5 || positionState == 10){
        // Ideal LINE. Only the back LEFT sensor needs to change
        Serial.println("ERROR: SHOULD NOT START TURNS ON LINES?");
        //finishCondition = sideLeft_changed;
        finishCondition = (sideLeftCount > 0);
      }

      if(positionState == 6 || positionState == 9){
        // Ideal CROSS. Only the front RIGHT and back RIGHT sensors needs to change
        //finishCondition = (sideLeft_changed && sideRight_changed);
        finishCondition = ((sideLeftCount > 0 && sideRightCount > 0) || sideLeftCount == 2); //|| (initialSensorReading_left == initialSensorReading_right;
      }

      if(positionState == 4 || positionState == 11){
        // CROSS deviating left
        //finishCondition = right_changed;
        Serial.println(F("ERROR: SHOULD OF WIGGLED BEFORE"));
        finishCondition = (frontRightCount > 0);
      }  
 
      if(positionState == 7 || positionState == 8){
        // CROSS deviating right
        //finishCondition = right_changed;
        Serial.println(F("ERROR: SHOULD OF WIGGLED BEFORE"));
        finishCondition = (frontRightCount > 0);
      }   
      

      // Trying new tings
      // finishCondition = (frontRightCount > 0);
      
      if(finishCondition){
          consecutiveCollisions = 0; // Movement did not end in a collision
          toggleColourState();
          Movement::stopMovement();
          resetFlagsAndCounts();
          Communication::setCurState(SLAVE_STOPPED);
      }
      
      break;
    
    default:
      // Can only end up here if the buggy has stopped due to an interrupt
      Serial.println("motorCorrection: interrupt triggered");
      
  } // end switch 

  // FOR TESTING ONLY REMOVE
//  consecutiveCollisions = 0; // Movement did not end in a collision
//  toggleColourState();
//  Movement::stopMovement();
//  resetFlagsAndCounts();    
//  Communication::setCurState(SLAVE_STOPPED);
  
} // end func

/**
 * DRY - Reseting all the sensor flags (if colour has changed) and counters (how many times they have changed)
 * for a given movement
 */
void SensorControl::resetFlagsAndCounts(){
  frontLeftFlag   = false;
  frontRightFlag  = false;
  sideLeftFlag    = false;
  sideRightFlag   = false;
  frontLeftCount  = 0;
  frontRightCount = 0;
  sideLeftCount   = 0;
  sideRightCount  = 0;      
}

/**
 *  Using the sensor values, calculate how many times they have transitioned
 */
void SensorControl::checkTransitions(){
  /*
   * The following conditions toggle and increment the transition count
   */

   // Front right
  if(right_changed == true){
    if(frontRightFlag == false){
      //Serial.println("Front right transition");
      frontRightFlag = true;
      frontRightCount++;
    }
  }else{
    if(frontRightFlag == true){
      //Serial.println("Front right transition");
      frontRightFlag = false;
      frontRightCount++;
    }
  }

  // Front left
  if(left_changed == true){
    if(frontLeftFlag == false){
      //Serial.println("Front left transition");
      frontLeftFlag = true;
      frontLeftCount++;
    }
  }else{
    if(frontLeftFlag == true){
      //Serial.println("Front left transition");
      frontLeftFlag = false;
      frontLeftCount++;
    }
  }

  // Side right
  if(sideRight_changed == true){
    if(sideRightFlag == false){
      //Serial.println("Side right transition");
      sideRightFlag = true;
      sideRightCount++;
    }
  }else{
    if(sideRightFlag == true){
      //Serial.println("Side right transition");
      sideRightFlag = false;
      sideRightCount++;
    }
  }

  // Side left
  if(sideLeft_changed == true){
    if(sideLeftFlag == false){
      //Serial.println("Side left transition");
      sideLeftFlag = true;
      sideLeftCount++;
    }
  }else{
    if(sideLeftFlag == true){
      //Serial.println("Side left transition");
      sideLeftFlag = false;
      sideLeftCount++;
    }
  }
}

/**
 * Toggle between BLACK_WHITE and WHITE_BLACK
 */
void SensorControl::toggleColourState(){
  if(currentColourState == WHITE_BLACK){
    Serial.println("BLACK_WHITE state");
    currentColourState = BLACK_WHITE;
  }else{
    Serial.println("WHITE_BLACK state");
    currentColourState = WHITE_BLACK;
  } 
}


/**
 * Convert the movement enum to a string
 */
String SensorControl::colourToString(colour c){
  switch(c){
    case WHITE:
      return "WHITE";
      break;
    case BLACK:
      return "BLACK";
      break;
    default:
      return "UNKNOWN";
  }
}

/**
 * Convert colourState enum to a string
 */
String SensorControl::getColourState(colourState cs){
  switch(cs){
    case WHITE_BLACK:
      return "WHITE_BLACK";
      break;
    case BLACK_WHITE:
      return "BLACK_WHITE";
      break;
    default:
      return "UNKNOWN"; 
  }
}


