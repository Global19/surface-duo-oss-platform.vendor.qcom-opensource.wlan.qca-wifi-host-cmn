/*
 * Copyright (c) 2017 The Linux Foundation. All rights reserved.
 *
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/**
 * DOC: Implement API's specific to Regulatory component.
 */

#include <qdf_status.h>
#include <wmi_unified_api.h>
#include <wmi_unified_priv.h>
#include <wmi_unified_reg_api.h>

QDF_STATUS wmi_extract_reg_chan_list_update_event(void *wmi_hdl,
						  uint8_t *evt_buf,
						  struct cur_regulatory_info
						  *reg_info,
						  uint32_t len)
{
	struct wmi_unified *wmi_handle = (struct wmi_unified *)wmi_hdl;

	if (wmi_handle->ops->extract_reg_chan_list_update_event)
		return wmi_handle->ops->extract_reg_chan_list_update_event
			(wmi_handle,
			 evt_buf, reg_info, len);

	return QDF_STATUS_E_FAILURE;
}

/*
 * wmi_unified_send_start_11d_scan_cmd() - start 11d scan
 * @wmi_handle: wmi handle
 * @start_11d_scan: pointer to 11d scan start req.
 *
 * Return: QDF_STATUS_SUCCESS on success, QDF_STATUS_E_** on error
 */
QDF_STATUS wmi_unified_send_start_11d_scan_cmd(wmi_unified_t wmi_handle,
		struct reg_start_11d_scan_req *start_11d_scan)
{
	if (wmi_handle->ops->send_start_11d_scan_cmd)
		return wmi_handle->ops->send_start_11d_scan_cmd(wmi_handle,
				start_11d_scan);

	return QDF_STATUS_E_FAILURE;
}

/*
 * wmi_unified_send_stop_11d_scan_cmd() - stop 11d scan
 * @wmi_handle: wmi handle
 * @stop_11d_scan: pointer to 11d scan stop req.
 *
 * Return: QDF_STATUS_SUCCESS on success, QDF_STATUS_E_** on error
 */
QDF_STATUS wmi_unified_send_stop_11d_scan_cmd(wmi_unified_t wmi_handle,
		struct reg_stop_11d_scan_req *stop_11d_scan)
{
	if (wmi_handle->ops->send_stop_11d_scan_cmd)
		return wmi_handle->ops->send_stop_11d_scan_cmd(wmi_handle,
				stop_11d_scan);

	return QDF_STATUS_E_FAILURE;
}

QDF_STATUS wmi_extract_reg_11d_new_cc_event(void *wmi_hdl,
		uint8_t *evt_buf,
		struct reg_11d_new_country *reg_11d_new_cc,
		uint32_t len)
{
	struct wmi_unified *wmi_handle = (struct wmi_unified *)wmi_hdl;

	if (wmi_handle->ops->extract_reg_11d_new_country_event)
		return wmi_handle->ops->extract_reg_11d_new_country_event(
				wmi_handle, evt_buf, reg_11d_new_cc, len);

	return QDF_STATUS_E_FAILURE;
}

