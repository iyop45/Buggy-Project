#pragma once

/*
* Copyright 2016 Google Inc.
*
* Use of this source code is governed by a BSD-style license that can be
* found in the LICENSE file.
*/

#ifndef PNGPREFIX_H
#define PNGPREFIX_H

/*
*  This allows linking to multiple versions of libpng. This way clients can use a
*  different version of libpng, if they desire, while SkCodec can use the version
*  we test with.
*/

#define png_sRGB_table skia_png_sRGB_table
#define png_sRGB_base skia_png_sRGB_base
#define png_sRGB_delta skia_png_sRGB_delta
#define png_zstream_error skia_png_zstream_error
#define png_free_buffer_list skia_png_free_buffer_list
#define png_fixed skia_png_fixed
#define png_user_version_check skia_png_user_version_check
#define png_malloc_base skia_png_malloc_base
#define png_malloc_array skia_png_malloc_array
#define png_realloc_array skia_png_realloc_array
#define png_create_png_struct skia_png_create_png_struct
#define png_destroy_png_struct skia_png_destroy_png_struct
#define png_free_jmpbuf skia_png_free_jmpbuf
#define png_zalloc skia_png_zalloc
#define png_zfree skia_png_zfree
#define png_default_read_data skia_png_default_read_data
#define png_push_fill_buffer skia_png_push_fill_buffer
#define png_default_write_data skia_png_default_write_data
#define png_default_flush skia_png_default_flush
#define png_reset_crc skia_png_reset_crc
#define png_write_data skia_png_write_data
#define png_read_sig skia_png_read_sig
#define png_read_chunk_header skia_png_read_chunk_header
#define png_read_data skia_png_read_data
#define png_crc_read skia_png_crc_read
#define png_crc_finish skia_png_crc_finish
#define png_crc_error skia_png_crc_error
#define png_calculate_crc skia_png_calculate_crc
#define png_flush skia_png_flush
#define png_write_IHDR skia_png_write_IHDR
#define png_write_PLTE skia_png_write_PLTE
#define png_compress_IDAT skia_png_compress_IDAT
#define png_write_IEND skia_png_write_IEND
#define png_write_gAMA_fixed skia_png_write_gAMA_fixed
#define png_write_sBIT skia_png_write_sBIT
#define png_write_cHRM_fixed skia_png_write_cHRM_fixed
#define png_write_sRGB skia_png_write_sRGB
#define png_write_iCCP skia_png_write_iCCP
#define png_write_sPLT skia_png_write_sPLT
#define png_write_tRNS skia_png_write_tRNS
#define png_write_bKGD skia_png_write_bKGD
#define png_write_hIST skia_png_write_hIST
#define png_write_tEXt skia_png_write_tEXt
#define png_write_zTXt skia_png_write_zTXt
#define png_write_iTXt skia_png_write_iTXt
#define png_set_text_2 skia_png_set_text_2
#define png_write_oFFs skia_png_write_oFFs
#define png_write_pCAL skia_png_write_pCAL
#define png_write_pHYs skia_png_write_pHYs
#define png_write_tIME skia_png_write_tIME
#define png_write_sCAL_s skia_png_write_sCAL_s
#define png_write_finish_row skia_png_write_finish_row
#define png_write_start_row skia_png_write_start_row
#define png_combine_row skia_png_combine_row
#define png_do_read_interlace skia_png_do_read_interlace
#define png_do_write_interlace skia_png_do_write_interlace
#define png_read_filter_row skia_png_read_filter_row
#define png_read_filter_row_up_neon skia_png_read_filter_row_up_neon
#define png_read_filter_row_sub3_neon skia_png_read_filter_row_sub3_neon
#define png_read_filter_row_sub4_neon skia_png_read_filter_row_sub4_neon
#define png_read_filter_row_avg3_neon skia_png_read_filter_row_avg3_neon
#define png_read_filter_row_avg4_neon skia_png_read_filter_row_avg4_neon
#define png_read_filter_row_paeth3_neon skia_png_read_filter_row_paeth3_neon
#define png_read_filter_row_paeth4_neon skia_png_read_filter_row_paeth4_neon
#define png_read_filter_row_sub3_sse2 skia_png_read_filter_row_sub3_sse2
#define png_read_filter_row_sub4_sse2 skia_png_read_filter_row_sub4_sse2
#define png_read_filter_row_avg3_sse2 skia_png_read_filter_row_avg3_sse2
#define png_read_filter_row_avg4_sse2 skia_png_read_filter_row_avg4_sse2
#define png_read_filter_row_paeth3_sse2 skia_png_read_filter_row_paeth3_sse2
#define png_read_filter_row_paeth4_sse2 skia_png_read_filter_row_paeth4_sse2
#define png_write_find_filter skia_png_write_find_filter
#define png_read_IDAT_data skia_png_read_IDAT_data
#define png_read_finish_IDAT skia_png_read_finish_IDAT
#define png_read_finish_row skia_png_read_finish_row
#define png_read_start_row skia_png_read_start_row
#define png_read_transform_info skia_png_read_transform_info
#define png_do_read_filler skia_png_do_read_filler
#define png_do_read_swap_alpha skia_png_do_read_swap_alpha
#define png_do_write_swap_alpha skia_png_do_write_swap_alpha
#define png_do_read_invert_alpha skia_png_do_read_invert_alpha
#define png_do_write_invert_alpha skia_png_do_write_invert_alpha
#define png_do_strip_channel skia_png_do_strip_channel
#define png_do_swap skia_png_do_swap
#define png_do_packswap skia_png_do_packswap
#define png_do_rgb_to_gray skia_png_do_rgb_to_gray
#define png_do_gray_to_rgb skia_png_do_gray_to_rgb
#define png_do_unpack skia_png_do_unpack
#define png_do_unshift skia_png_do_unshift
#define png_do_invert skia_png_do_invert
#define png_do_scale_16_to_8 skia_png_do_scale_16_to_8
#define png_do_chop skia_png_do_chop
#define png_do_quantize skia_png_do_quantize
#define png_do_bgr skia_png_do_bgr
#define png_do_pack skia_png_do_pack
#define png_do_shift skia_png_do_shift
#define png_do_compose skia_png_do_compose
#define png_do_gamma skia_png_do_gamma
#define png_do_encode_alpha skia_png_do_encode_alpha
#define png_do_expand_palette skia_png_do_expand_palette
#define png_do_expand skia_png_do_expand
#define png_do_expand_16 skia_png_do_expand_16
#define png_handle_IHDR skia_png_handle_IHDR
#define png_handle_PLTE skia_png_handle_PLTE
#define png_handle_IEND skia_png_handle_IEND
#define png_handle_bKGD skia_png_handle_bKGD
#define png_handle_cHRM skia_png_handle_cHRM
#define png_handle_gAMA skia_png_handle_gAMA
#define png_handle_hIST skia_png_handle_hIST
#define png_handle_iCCP skia_png_handle_iCCP
#define png_handle_iTXt skia_png_handle_iTXt
#define png_handle_oFFs skia_png_handle_oFFs
#define png_handle_pCAL skia_png_handle_pCAL
#define png_handle_pHYs skia_png_handle_pHYs
#define png_handle_sBIT skia_png_handle_sBIT
#define png_handle_sCAL skia_png_handle_sCAL
#define png_handle_sPLT skia_png_handle_sPLT
#define png_handle_sRGB skia_png_handle_sRGB
#define png_handle_tEXt skia_png_handle_tEXt
#define png_handle_tIME skia_png_handle_tIME
#define png_handle_tRNS skia_png_handle_tRNS
#define png_handle_zTXt skia_png_handle_zTXt
#define png_check_chunk_name skia_png_check_chunk_name
#define png_handle_unknown skia_png_handle_unknown
#define png_chunk_unknown_handling skia_png_chunk_unknown_handling
#define png_do_read_transformations skia_png_do_read_transformations
#define png_do_write_transformations skia_png_do_write_transformations
#define png_init_read_transformations skia_png_init_read_transformations
#define png_push_read_chunk skia_png_push_read_chunk
#define png_push_read_sig skia_png_push_read_sig
#define png_push_check_crc skia_png_push_check_crc
#define png_push_crc_skip skia_png_push_crc_skip
#define png_push_crc_finish skia_png_push_crc_finish
#define png_push_save_buffer skia_png_push_save_buffer
#define png_push_restore_buffer skia_png_push_restore_buffer
#define png_push_read_IDAT skia_png_push_read_IDAT
#define png_process_IDAT_data skia_png_process_IDAT_data
#define png_push_process_row skia_png_push_process_row
#define png_push_handle_unknown skia_png_push_handle_unknown
#define png_push_have_info skia_png_push_have_info
#define png_push_have_end skia_png_push_have_end
#define png_push_have_row skia_png_push_have_row
#define png_push_read_end skia_png_push_read_end
#define png_process_some_data skia_png_process_some_data
#define png_read_push_finish_row skia_png_read_push_finish_row
#define png_push_handle_tEXt skia_png_push_handle_tEXt
#define png_push_read_tEXt skia_png_push_read_tEXt
#define png_push_handle_zTXt skia_png_push_handle_zTXt
#define png_push_read_zTXt skia_png_push_read_zTXt
#define png_push_handle_iTXt skia_png_push_handle_iTXt
#define png_push_read_iTXt skia_png_push_read_iTXt
#define png_do_read_intrapixel skia_png_do_read_intrapixel
#define png_do_write_intrapixel skia_png_do_write_intrapixel
#define png_colorspace_set_gamma skia_png_colorspace_set_gamma
#define png_colorspace_sync_info skia_png_colorspace_sync_info
#define png_colorspace_sync skia_png_colorspace_sync
#define png_colorspace_set_chromaticities skia_png_colorspace_set_chromaticities
#define png_colorspace_set_endpoints skia_png_colorspace_set_endpoints
#define png_colorspace_set_sRGB skia_png_colorspace_set_sRGB
#define png_colorspace_set_ICC skia_png_colorspace_set_ICC
#define png_icc_check_length skia_png_icc_check_length
#define png_icc_check_header skia_png_icc_check_header
#define png_icc_check_tag_table skia_png_icc_check_tag_table
#define png_icc_set_sRGB skia_png_icc_set_sRGB
#define png_colorspace_set_rgb_coefficients skia_png_colorspace_set_rgb_coefficients
#define png_check_IHDR skia_png_check_IHDR
#define png_do_check_palette_indexes skia_png_do_check_palette_indexes
#define png_fixed_error skia_png_fixed_error
#define png_safecat skia_png_safecat
#define png_format_number skia_png_format_number
#define png_warning_parameter skia_png_warning_parameter
#define png_warning_parameter_unsigned skia_png_warning_parameter_unsigned
#define png_warning_parameter_signed skia_png_warning_parameter_signed
#define png_formatted_warning skia_png_formatted_warning
#define png_app_warning skia_png_app_warning
#define png_app_error skia_png_app_error
#define png_chunk_report skia_png_chunk_report
#define png_ascii_from_fp skia_png_ascii_from_fp
#define png_ascii_from_fixed skia_png_ascii_from_fixed
#define png_check_fp_number skia_png_check_fp_number
#define png_check_fp_string skia_png_check_fp_string
#define png_muldiv skia_png_muldiv
#define png_muldiv_warn skia_png_muldiv_warn
#define png_reciprocal skia_png_reciprocal
#define png_reciprocal2 skia_png_reciprocal2
#define png_gamma_significant skia_png_gamma_significant
#define png_gamma_correct skia_png_gamma_correct
#define png_gamma_16bit_correct skia_png_gamma_16bit_correct
#define png_gamma_8bit_correct skia_png_gamma_8bit_correct
#define png_destroy_gamma_table skia_png_destroy_gamma_table
#define png_build_gamma_table skia_png_build_gamma_table
#define png_safe_error skia_png_safe_error
#define png_safe_warning skia_png_safe_warning
#define png_safe_execute skia_png_safe_execute
#define png_image_error skia_png_image_error
#define png_access_version_number skia_png_access_version_number
#define png_build_grayscale_palette skia_png_build_grayscale_palette
#define png_convert_to_rfc1123 skia_png_convert_to_rfc1123
#define png_convert_to_rfc1123_buffer skia_png_convert_to_rfc1123_buffer
#define png_create_info_struct skia_png_create_info_struct
#define png_data_freer skia_png_data_freer
#define png_destroy_info_struct skia_png_destroy_info_struct
#define png_free_data skia_png_free_data
#define png_get_copyright skia_png_get_copyright
#define png_get_header_ver skia_png_get_header_ver
#define png_get_header_version skia_png_get_header_version
#define png_get_io_ptr skia_png_get_io_ptr
#define png_get_libpng_ver skia_png_get_libpng_ver
#define png_handle_as_unknown skia_png_handle_as_unknown
#define png_image_free skia_png_image_free
#define png_info_init_3 skia_png_info_init_3
#define png_init_io skia_png_init_io
#define png_reset_zstream skia_png_reset_zstream
#define png_save_int_32 skia_png_save_int_32
#define png_set_option skia_png_set_option
#define png_set_sig_bytes skia_png_set_sig_bytes
#define png_sig_cmp skia_png_sig_cmp
#define png_benign_error skia_png_benign_error
#define png_chunk_benign_error skia_png_chunk_benign_error
#define png_chunk_error skia_png_chunk_error
#define png_chunk_warning skia_png_chunk_warning
#define png_error skia_png_error
#define png_get_error_ptr skia_png_get_error_ptr
#define png_longjmp skia_png_longjmp
#define png_set_error_fn skia_png_set_error_fn
#define png_set_longjmp_fn skia_png_set_longjmp_fn
#define png_warning skia_png_warning
#define png_get_bit_depth skia_png_get_bit_depth
#define png_get_bKGD skia_png_get_bKGD
#define png_get_channels skia_png_get_channels
#define png_get_cHRM skia_png_get_cHRM
#define png_get_cHRM_fixed skia_png_get_cHRM_fixed
#define png_get_cHRM_XYZ skia_png_get_cHRM_XYZ
#define png_get_cHRM_XYZ_fixed skia_png_get_cHRM_XYZ_fixed
#define png_get_chunk_cache_max skia_png_get_chunk_cache_max
#define png_get_chunk_malloc_max skia_png_get_chunk_malloc_max
#define png_get_color_type skia_png_get_color_type
#define png_get_compression_buffer_size skia_png_get_compression_buffer_size
#define png_get_compression_type skia_png_get_compression_type
#define png_get_filter_type skia_png_get_filter_type
#define png_get_gAMA skia_png_get_gAMA
#define png_get_gAMA_fixed skia_png_get_gAMA_fixed
#define png_get_hIST skia_png_get_hIST
#define png_get_iCCP skia_png_get_iCCP
#define png_get_IHDR skia_png_get_IHDR
#define png_get_image_height skia_png_get_image_height
#define png_get_image_width skia_png_get_image_width
#define png_get_interlace_type skia_png_get_interlace_type
#define png_get_io_chunk_type skia_png_get_io_chunk_type
#define png_get_io_state skia_png_get_io_state
#define png_get_oFFs skia_png_get_oFFs
#define png_get_palette_max skia_png_get_palette_max
#define png_get_pCAL skia_png_get_pCAL
#define png_get_pHYs skia_png_get_pHYs
#define png_get_pHYs_dpi skia_png_get_pHYs_dpi
#define png_get_pixel_aspect_ratio skia_png_get_pixel_aspect_ratio
#define png_get_pixel_aspect_ratio_fixed skia_png_get_pixel_aspect_ratio_fixed
#define png_get_pixels_per_inch skia_png_get_pixels_per_inch
#define png_get_pixels_per_meter skia_png_get_pixels_per_meter
#define png_get_PLTE skia_png_get_PLTE
#define png_get_rgb_to_gray_status skia_png_get_rgb_to_gray_status
#define png_get_rowbytes skia_png_get_rowbytes
#define png_get_rows skia_png_get_rows
#define png_get_sBIT skia_png_get_sBIT
#define png_get_sCAL skia_png_get_sCAL
#define png_get_sCAL_fixed skia_png_get_sCAL_fixed
#define png_get_sCAL_s skia_png_get_sCAL_s
#define png_get_signature skia_png_get_signature
#define png_get_sPLT skia_png_get_sPLT
#define png_get_sRGB skia_png_get_sRGB
#define png_get_text skia_png_get_text
#define png_get_tIME skia_png_get_tIME
#define png_get_tRNS skia_png_get_tRNS
#define png_get_unknown_chunks skia_png_get_unknown_chunks
#define png_get_user_chunk_ptr skia_png_get_user_chunk_ptr
#define png_get_user_height_max skia_png_get_user_height_max
#define png_get_user_width_max skia_png_get_user_width_max
#define png_get_valid skia_png_get_valid
#define png_get_x_offset_inches skia_png_get_x_offset_inches
#define png_get_x_offset_inches_fixed skia_png_get_x_offset_inches_fixed
#define png_get_x_offset_microns skia_png_get_x_offset_microns
#define png_get_x_offset_pixels skia_png_get_x_offset_pixels
#define png_get_x_pixels_per_inch skia_png_get_x_pixels_per_inch
#define png_get_x_pixels_per_meter skia_png_get_x_pixels_per_meter
#define png_get_y_offset_inches skia_png_get_y_offset_inches
#define png_get_y_offset_inches_fixed skia_png_get_y_offset_inches_fixed
#define png_get_y_offset_microns skia_png_get_y_offset_microns
#define png_get_y_offset_pixels skia_png_get_y_offset_pixels
#define png_get_y_pixels_per_inch skia_png_get_y_pixels_per_inch
#define png_get_y_pixels_per_meter skia_png_get_y_pixels_per_meter
#define png_calloc skia_png_calloc
#define png_free skia_png_free
#define png_free_default skia_png_free_default
#define png_get_mem_ptr skia_png_get_mem_ptr
#define png_malloc skia_png_malloc
#define png_malloc_default skia_png_malloc_default
#define png_malloc_warn skia_png_malloc_warn
#define png_set_mem_fn skia_png_set_mem_fn
#define png_get_progressive_ptr skia_png_get_progressive_ptr
#define png_process_data skia_png_process_data
#define png_process_data_pause skia_png_process_data_pause
#define png_process_data_skip skia_png_process_data_skip
#define png_progressive_combine_row skia_png_progressive_combine_row
#define png_set_progressive_read_fn skia_png_set_progressive_read_fn
#define png_create_read_struct skia_png_create_read_struct
#define png_create_read_struct_2 skia_png_create_read_struct_2
#define png_destroy_read_struct skia_png_destroy_read_struct
#define png_image_begin_read_from_file skia_png_image_begin_read_from_file
#define png_image_begin_read_from_memory skia_png_image_begin_read_from_memory
#define png_image_begin_read_from_stdio skia_png_image_begin_read_from_stdio
#define png_image_finish_read skia_png_image_finish_read
#define png_read_end skia_png_read_end
#define png_read_image skia_png_read_image
#define png_read_info skia_png_read_info
#define png_read_png skia_png_read_png
#define png_read_row skia_png_read_row
#define png_read_rows skia_png_read_rows
#define png_read_update_info skia_png_read_update_info
#define png_set_read_status_fn skia_png_set_read_status_fn
#define png_start_read_image skia_png_start_read_image
#define png_set_read_fn skia_png_set_read_fn
#define png_set_alpha_mode skia_png_set_alpha_mode
#define png_set_alpha_mode_fixed skia_png_set_alpha_mode_fixed
#define png_set_background skia_png_set_background
#define png_set_background_fixed skia_png_set_background_fixed
#define png_set_crc_action skia_png_set_crc_action
#define png_set_expand skia_png_set_expand
#define png_set_expand_16 skia_png_set_expand_16
#define png_set_expand_gray_1_2_4_to_8 skia_png_set_expand_gray_1_2_4_to_8
#define png_set_gamma skia_png_set_gamma
#define png_set_gamma_fixed skia_png_set_gamma_fixed
#define png_set_gray_to_rgb skia_png_set_gray_to_rgb
#define png_set_palette_to_rgb skia_png_set_palette_to_rgb
#define png_set_quantize skia_png_set_quantize
#define png_set_read_user_transform_fn skia_png_set_read_user_transform_fn
#define png_set_rgb_to_gray skia_png_set_rgb_to_gray
#define png_set_rgb_to_gray_fixed skia_png_set_rgb_to_gray_fixed
#define png_set_scale_16 skia_png_set_scale_16
#define png_set_strip_16 skia_png_set_strip_16
#define png_set_strip_alpha skia_png_set_strip_alpha
#define png_set_tRNS_to_alpha skia_png_set_tRNS_to_alpha
#define png_get_int_32 skia_png_get_int_32
#define png_get_uint_16 skia_png_get_uint_16
#define png_get_uint_31 skia_png_get_uint_31
#define png_get_uint_32 skia_png_get_uint_32
#define png_permit_mng_features skia_png_permit_mng_features
#define png_set_benign_errors skia_png_set_benign_errors
#define png_set_bKGD skia_png_set_bKGD
#define png_set_check_for_invalid_index skia_png_set_check_for_invalid_index
#define png_set_cHRM skia_png_set_cHRM
#define png_set_cHRM_fixed skia_png_set_cHRM_fixed
#define png_set_cHRM_XYZ skia_png_set_cHRM_XYZ
#define png_set_cHRM_XYZ_fixed skia_png_set_cHRM_XYZ_fixed
#define png_set_chunk_cache_max skia_png_set_chunk_cache_max
#define png_set_chunk_malloc_max skia_png_set_chunk_malloc_max
#define png_set_compression_buffer_size skia_png_set_compression_buffer_size
#define png_set_gAMA skia_png_set_gAMA
#define png_set_gAMA_fixed skia_png_set_gAMA_fixed
#define png_set_hIST skia_png_set_hIST
#define png_set_iCCP skia_png_set_iCCP
#define png_set_IHDR skia_png_set_IHDR
#define png_set_invalid skia_png_set_invalid
#define png_set_keep_unknown_chunks skia_png_set_keep_unknown_chunks
#define png_set_oFFs skia_png_set_oFFs
#define png_set_pCAL skia_png_set_pCAL
#define png_set_pHYs skia_png_set_pHYs
#define png_set_PLTE skia_png_set_PLTE
#define png_set_read_user_chunk_fn skia_png_set_read_user_chunk_fn
#define png_set_rows skia_png_set_rows
#define png_set_sBIT skia_png_set_sBIT
#define png_set_sCAL skia_png_set_sCAL
#define png_set_sCAL_fixed skia_png_set_sCAL_fixed
#define png_set_sCAL_s skia_png_set_sCAL_s
#define png_set_sPLT skia_png_set_sPLT
#define png_set_sRGB skia_png_set_sRGB
#define png_set_sRGB_gAMA_and_cHRM skia_png_set_sRGB_gAMA_and_cHRM
#define png_set_text skia_png_set_text
#define png_set_tIME skia_png_set_tIME
#define png_set_tRNS skia_png_set_tRNS
#define png_set_unknown_chunk_location skia_png_set_unknown_chunk_location
#define png_set_unknown_chunks skia_png_set_unknown_chunks
#define png_set_user_limits skia_png_set_user_limits
#define png_get_current_pass_number skia_png_get_current_pass_number
#define png_get_current_row_number skia_png_get_current_row_number
#define png_get_user_transform_ptr skia_png_get_user_transform_ptr
#define png_set_add_alpha skia_png_set_add_alpha
#define png_set_bgr skia_png_set_bgr
#define png_set_filler skia_png_set_filler
#define png_set_interlace_handling skia_png_set_interlace_handling
#define png_set_invert_alpha skia_png_set_invert_alpha
#define png_set_invert_mono skia_png_set_invert_mono
#define png_set_packing skia_png_set_packing
#define png_set_packswap skia_png_set_packswap
#define png_set_shift skia_png_set_shift
#define png_set_swap skia_png_set_swap
#define png_set_swap_alpha skia_png_set_swap_alpha
#define png_set_user_transform_info skia_png_set_user_transform_info
#define png_set_write_fn skia_png_set_write_fn
#define png_convert_from_struct_tm skia_png_convert_from_struct_tm
#define png_convert_from_time_t skia_png_convert_from_time_t
#define png_create_write_struct skia_png_create_write_struct
#define png_create_write_struct_2 skia_png_create_write_struct_2
#define png_destroy_write_struct skia_png_destroy_write_struct
#define png_image_write_to_file skia_png_image_write_to_file
#define png_image_write_to_stdio skia_png_image_write_to_stdio
#define png_set_compression_level skia_png_set_compression_level
#define png_set_compression_mem_level skia_png_set_compression_mem_level
#define png_set_compression_method skia_png_set_compression_method
#define png_set_compression_strategy skia_png_set_compression_strategy
#define png_set_compression_window_bits skia_png_set_compression_window_bits
#define png_set_filter skia_png_set_filter
#define png_set_filter_heuristics skia_png_set_filter_heuristics
#define png_set_filter_heuristics_fixed skia_png_set_filter_heuristics_fixed
#define png_set_flush skia_png_set_flush
#define png_set_text_compression_level skia_png_set_text_compression_level
#define png_set_text_compression_mem_level skia_png_set_text_compression_mem_level
#define png_set_text_compression_method skia_png_set_text_compression_method
#define png_set_text_compression_strategy skia_png_set_text_compression_strategy
#define png_set_text_compression_window_bits skia_png_set_text_compression_window_bits
#define png_set_write_status_fn skia_png_set_write_status_fn
#define png_set_write_user_transform_fn skia_png_set_write_user_transform_fn
#define png_write_end skia_png_write_end
#define png_write_flush skia_png_write_flush
#define png_write_image skia_png_write_image
#define png_write_info skia_png_write_info
#define png_write_info_before_PLTE skia_png_write_info_before_PLTE
#define png_write_png skia_png_write_png
#define png_write_row skia_png_write_row
#define png_write_rows skia_png_write_rows
#define png_save_uint_16 skia_png_save_uint_16
#define png_save_uint_32 skia_png_save_uint_32
#define png_write_chunk skia_png_write_chunk
#define png_write_chunk_data skia_png_write_chunk_data
#define png_write_chunk_start skia_png_write_chunk_start
#define png_write_chunk_end skia_png_write_chunk_end
#define png_write_sig skia_png_write_sig
#define png_init_filter_functions_neon skia_png_init_filter_functions_neon
#define png_init_filter_functions_sse2 skia_png_init_filter_functions_sse2

#endif  // PNGPREFIX_H