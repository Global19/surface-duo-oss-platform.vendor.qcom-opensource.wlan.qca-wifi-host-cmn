/*
 * Copyright (c) 2017 The Linux Foundation. All rights reserved.
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
 * DOC: contains nan definitions exposed to other modules
 */

#ifdef WLAN_FEATURE_NAN_CONVERGENCE
#ifndef _NAN_PUBLIC_STRUCTS_H_
#define _NAN_PUBLIC_STRUCTS_H_

#include "qdf_types.h"
#include "qdf_status.h"

struct wlan_objmgr_psoc;
struct wlan_objmgr_vdev;

#define IFACE_NAME_SIZE 64

#define NAN_DATAPATH_INF_CREATE_REQ                     0
#define NAN_DATAPATH_INF_CREATE_RSP                     1
#define NAN_DATAPATH_INF_DELETE_REQ                     2
#define NAN_DATAPATH_INF_DELETE_RSP                     3
#define NDP_INITIATOR_REQ                               4
#define NDP_INITIATOR_RSP                               5
#define NDP_RESPONDER_REQ                               6
#define NDP_RESPONDER_RSP                               7
#define NDP_END_REQ                                     8
#define NDP_END_RSP                                     9
#define NDP_INDICATION                                  10
#define NDP_CONFIRM                                     11
#define NDP_END_IND                                     12
#define NDP_NEW_PEER                                    13
#define NDP_PEER_DEPARTED                               14

/**
 * enum nan_datapath_status_type - NDP status type
 * @NAN_DATAPATH_RSP_STATUS_SUCCESS: request was successful
 * @NAN_DATAPATH_RSP_STATUS_ERROR: request failed
 */
enum nan_datapath_status_type {
	NAN_DATAPATH_RSP_STATUS_SUCCESS = 0x00,
	NAN_DATAPATH_RSP_STATUS_ERROR = 0x01,
};

/**
 * enum nan_datapath_reason_code - NDP command rsp reason code value
 * @NDP_UNSUPPORTED_CONCURRENCY: Will be used in unsupported concurrency cases
 * @NDP_NAN_DATA_IFACE_CREATE_FAILED: ndi create failed
 * @NDP_NAN_DATA_IFACE_DELETE_FAILED: ndi delete failed
 * @NDP_DATA_INITIATOR_REQ_FAILED: data initiator request failed
 * @NDP_DATA_RESPONDER_REQ_FAILED: data responder request failed
 * @NDP_INVALID_SERVICE_INSTANCE_ID: invalid service instance id
 * @NDP_INVALID_NDP_INSTANCE_ID: invalid ndp instance id
 * @NDP_INVALID_RSP_CODE: invalid response code in ndp responder request
 * @NDP_INVALID_APP_INFO_LEN: invalid app info length
 * @NDP_NMF_REQ_FAIL: OTA nan mgmt frame failure for data request
 * @NDP_NMF_RSP_FAIL: OTA nan mgmt frame failure for data response
 * @NDP_NMF_CNF_FAIL: OTA nan mgmt frame failure for confirm
 * @NDP_END_FAILED: ndp end failed
 * @NDP_NMF_END_REQ_FAIL: OTA nan mgmt frame failure for data end
 * @NDP_VENDOR_SPECIFIC_ERROR: other vendor specific failures
 */
enum nan_datapath_reason_code {
	NAN_DATAPATH_UNSUPPORTED_CONCURRENCY = 9000,
	NAN_DATAPATH_NAN_DATA_IFACE_CREATE_FAILED = 9001,
	NAN_DATAPATH_NAN_DATA_IFACE_DELETE_FAILED = 9002,
	NAN_DATAPATH_DATA_INITIATOR_REQ_FAILED = 9003,
	NAN_DATAPATH_DATA_RESPONDER_REQ_FAILED = 9004,
	NAN_DATAPATH_INVALID_SERVICE_INSTANCE_ID = 9005,
	NAN_DATAPATH_INVALID_NDP_INSTANCE_ID = 9006,
	NAN_DATAPATH_INVALID_RSP_CODE = 9007,
	NAN_DATAPATH_INVALID_APP_INFO_LEN = 9008,
	NAN_DATAPATH_NMF_REQ_FAIL = 9009,
	NAN_DATAPATH_NMF_RSP_FAIL = 9010,
	NAN_DATAPATH_NMF_CNF_FAIL = 9011,
	NAN_DATAPATH_END_FAILED = 9012,
	NAN_DATAPATH_NMF_END_REQ_FAIL = 9013,
	/* 9500 onwards vendor specific error codes */
	NAN_DATAPATH_VENDOR_SPECIFIC_ERROR = 9500,
};

/**
 * enum nan_datapath_response_code - responder's response code to nan data path
 * request
 * @NAN_DATAPATH_RESPONSE_ACCEPT: ndp request accepted
 * @NAN_DATAPATH_RESPONSE_REJECT: ndp request rejected
 * @NAN_DATAPATH_RESPONSE_DEFER: ndp request deferred until later (response to
 * follow any time later)
 *
 */
enum nan_datapath_response_code {
	NAN_DATAPATH_RESPONSE_ACCEPT = 0,
	NAN_DATAPATH_RESPONSE_REJECT = 1,
	NAN_DATAPATH_RESPONSE_DEFER = 2,
};

/**
 * enum nan_datapath_accept_policy - nan data path accept policy
 * @NAN_DATAPATH_ACCEPT_POLICY_NONE: the framework will decide the policy
 * @NAN_DATAPATH_ACCEPT_POLICY_ALL: accept policy offloaded to fw
 *
 */
enum nan_datapath_accept_policy {
	NAN_DATAPATH_ACCEPT_POLICY_NONE = 0,
	NAN_DATAPATH_ACCEPT_POLICY_ALL = 1,
};

/**
 * enum nan_datapath_self_role - nan data path role
 * @NAN_DATAPATH_ROLE_INITIATOR: initiator of nan data path request
 * @NAN_DATAPATH_ROLE_RESPONDER: responder to nan data path request
 *
 */
enum nan_datapath_self_role {
	NAN_DATAPATH_ROLE_INITIATOR = 0,
	NAN_DATAPATH_ROLE_RESPONDER = 1,
};

/**
 * enum nan_datapath_end_type - NDP end type
 * @NAN_DATAPATH_END_TYPE_UNSPECIFIED: type is unspecified
 * @NAN_DATAPATH_END_TYPE_PEER_UNAVAILABLE: type is peer unavailable
 * @NAN_DATAPATH_END_TYPE_OTA_FRAME: NDP end frame received from peer
 *
 */
enum nan_datapath_end_type {
	NAN_DATAPATH_END_TYPE_UNSPECIFIED = 0x00,
	NAN_DATAPATH_END_TYPE_PEER_UNAVAILABLE = 0x01,
	NAN_DATAPATH_END_TYPE_OTA_FRAME = 0x02,
};

/**
 * enum nan_datapath_end_reason_code - NDP end reason code
 * @NAN_DATAPATH_END_REASON_UNSPECIFIED: reason is unspecified
 * @NAN_DATAPATH_END_REASON_INACTIVITY: reason is peer inactivity
 * @NAN_DATAPATH_END_REASON_PEER_DATA_END: data end indication received from
 * peer
 *
 */
enum nan_datapath_end_reason_code {
	NAN_DATAPATH_END_REASON_UNSPECIFIED = 0x00,
	NAN_DATAPATH_END_REASON_INACTIVITY = 0x01,
	NAN_DATAPATH_END_REASON_PEER_DATA_END = 0x02,
};

/** enum nan_datapath_state - NAN datapath states
 * @NAN_DATA_NDI_CREATING_STATE: NDI create is in progress
 * @NAN_DATA_NDI_CREATED_STATE: NDI successfully crated
 * @NAN_DATA_NDI_DELETING_STATE: NDI delete is in progress
 * @NAN_DATA_NDI_DELETED_STATE: NDI delete is in progress
 * @NAN_DATA_PEER_CREATE_STATE: Peer create is in progress
 * @NAN_DATA_PEER_DELETE_STATE: Peer delete is in progrss
 * @NAN_DATA_CONNECTING_STATE: Data connection in progress
 * @NAN_DATA_CONNECTED_STATE: Data connection successful
 * @NAN_DATA_END_STATE: NDP end is in progress
 * @NAN_DATA_DISCONNECTED_STATE: NDP is in disconnected state
 */
enum nan_datapath_state {
	NAN_DATA_INVALID_STATE = -1,
	NAN_DATA_NDI_CREATING_STATE = 0,
	NAN_DATA_NDI_CREATED_STATE = 1,
	NAN_DATA_NDI_DELETING_STATE = 2,
	NAN_DATA_NDI_DELETED_STATE = 3,
	NAN_DATA_PEER_CREATE_STATE = 4,
	NAN_DATA_PEER_DELETE_STATE = 5,
	NAN_DATA_CONNECTING_STATE = 6,
	NAN_DATA_CONNECTED_STATE = 7,
	NAN_DATA_END_STATE = 8,
	NAN_DATA_DISCONNECTED_STATE = 9,
};

/**
 * struct nan_datapath_app_info - application info shared during ndp setup
 * @ndp_app_info_len: ndp app info length
 * @ndp_app_info: variable length application information
 *
 */
struct nan_datapath_app_info {
	uint32_t ndp_app_info_len;
	uint8_t *ndp_app_info;
};

/**
 * struct nan_datapath_cfg - ndp configuration
 * @ndp_cfg_len: ndp configuration length
 * @ndp_cfg: variable length ndp configuration
 *
 */
struct nan_datapath_cfg {
	uint32_t ndp_cfg_len;
	uint8_t *ndp_cfg;
};

/**
 * struct nan_datapath_pmk - structure to hold pairwise master key
 * @pmk_len: length of pairwise master key
 * @pmk: buffer containing pairwise master key
 *
 */
struct nan_datapath_pmk {
	uint32_t pmk_len;
	uint8_t *pmk;
};

/**
 * struct nan_datapath_scid - structure to hold sceurity context identifier
 * @scid_len: length of scid
 * @scid: scid
 *
 */
struct nan_datapath_scid {
	uint32_t scid_len;
	uint8_t *scid;
};

/**
 * struct ndp_passphrase - structure to hold passphrase
 * @passphrase_len: length of passphrase
 * @passphrase: buffer containing passphrase
 *
 */
struct ndp_passphrase {
	uint32_t passphrase_len;
	uint8_t *passphrase;
};

/**
 * struct ndp_service_name - structure to hold service_name
 * @service_name_len: length of service_name
 * @service_name: buffer containing service_name
 *
 */
struct ndp_service_name {
	uint32_t service_name_len;
	uint8_t *service_name;
};

/**
 * struct peer_nan_datapath_map  - mapping of NDP instances to peer to VDEV
 * @vdev_id: session id of the interface over which ndp is being created
 * @peer_ndi_mac_addr: peer NDI mac address
 * @num_active_ndp_sessions: number of active NDP sessions on the peer
 * @type: NDP end indication type
 * @reason_code: NDP end indication reason code
 * @ndp_instance_id: NDP instance ID
 *
 */
struct peer_nan_datapath_map {
	uint32_t vdev_id;
	struct qdf_mac_addr peer_ndi_mac_addr;
	uint32_t num_active_ndp_sessions;
	enum nan_datapath_end_type type;
	enum nan_datapath_end_reason_code reason_code;
	uint32_t ndp_instance_id;
};

/**
 * struct nan_datapath_inf_create_req - ndi create request params
 * @transaction_id: unique identifier
 * @iface_name: interface name
 *
 */
struct nan_datapath_inf_create_req {
	uint32_t transaction_id;
	char  iface_name[IFACE_NAME_SIZE];
};

/*
 * struct nan_datapath_inf_create_rsp - ndi create response params
 * @status: request status
 * @reason: reason if any
 *
 */
struct nan_datapath_inf_create_rsp {
	uint32_t status;
	uint32_t reason;
	uint8_t sta_id;
};

/**
 * struct nan_datapath_inf_delete_rsp - ndi delete response params
 * @status: request status
 * @reason: reason if any
 *
 */
struct nan_datapath_inf_delete_rsp {
	uint32_t status;
	uint32_t reason;
};

/**
 * struct nan_datapath_initiator_req - ndp initiator request params
 * @transaction_id: unique identifier
 * @vdev_id: session id of the interface over which ndp is being created
 * @channel: suggested channel for ndp creation
 * @channel_cfg: channel config, 0=no channel, 1=optional, 2=mandatory
 * @service_instance_id: Service identifier
 * @peer_discovery_mac_addr: Peer's discovery mac address
 * @self_ndi_mac_addr: self NDI mac address
 * @ndp_config: ndp configuration params
 * @ndp_info: ndp application info
 * @ncs_sk_type: indicates NCS_SK_128 or NCS_SK_256
 * @pmk: pairwise master key
 * @passphrase: passphrase
 * @service_name: service name
 */
struct nan_datapath_initiator_req {
	struct wlan_objmgr_vdev *vdev;
	uint32_t transaction_id;
	uint32_t channel;
	uint32_t channel_cfg;
	uint32_t service_instance_id;
	uint32_t ncs_sk_type;
	struct qdf_mac_addr peer_discovery_mac_addr;
	struct qdf_mac_addr self_ndi_mac_addr;
	struct nan_datapath_cfg ndp_config;
	struct nan_datapath_app_info ndp_info;
	struct nan_datapath_pmk pmk;
	struct ndp_passphrase passphrase;
	struct ndp_service_name service_name;
};

/**
 * struct nan_datapath_initiator_rsp - response event from FW
 * @transaction_id: unique identifier
 * @vdev_id: session id of the interface over which ndp is being created
 * @ndp_instance_id: locally created NDP instance ID
 * @status: status of the ndp request
 * @reason: reason for failure if any
 *
 */
struct nan_datapath_initiator_rsp {
	struct wlan_objmgr_vdev *vdev;
	uint32_t transaction_id;
	uint32_t ndp_instance_id;
	uint32_t status;
	uint32_t reason;
};

/**
 * struct nan_datapath_responder_req - responder's response to ndp create
 * request
 * @transaction_id: unique identifier
 * @vdev_id: session id of the interface over which ndp is being created
 * @ndp_instance_id: locally created NDP instance ID
 * @ndp_rsp: response to the ndp create request
 * @ndp_config: ndp configuration params
 * @ndp_info: ndp application info
 * @pmk: pairwise master key
 * @ncs_sk_type: indicates NCS_SK_128 or NCS_SK_256
 * @passphrase: passphrase
 * @service_name: service name
 *
 */
struct nan_datapath_responder_req {
	struct wlan_objmgr_vdev *vdev;
	uint32_t transaction_id;
	uint32_t ndp_instance_id;
	enum nan_datapath_response_code ndp_rsp;
	struct nan_datapath_cfg ndp_config;
	struct nan_datapath_app_info ndp_info;
	struct nan_datapath_pmk pmk;
	uint32_t ncs_sk_type;
	struct ndp_passphrase passphrase;
	struct ndp_service_name service_name;
};

/**
 * struct nan_datapath_responder_rsp - response to responder's request
 * @transaction_id: unique identifier
 * @vdev_id: session id of the interface over which ndp is being created
 * @status: command status
 * @reason: reason for failure if any
 * @peer_mac_addr: Peer's mac address
 * @create_peer: Flag to indicate to create peer
 */
struct nan_datapath_responder_rsp {
	struct wlan_objmgr_vdev *vdev;
	uint32_t transaction_id;
	uint32_t status;
	uint32_t reason;
	struct qdf_mac_addr peer_mac_addr;
	bool create_peer;
};

/**
 * struct nan_datapath_end_req - ndp end request
 * @transaction_id: unique transaction identifier
 * @num_ndp_instances: number of ndp instances to be terminated
 * @ndp_ids: pointer to array of ndp_instance_id to be terminated
 *
 */
struct nan_datapath_end_req {
	struct wlan_objmgr_vdev *vdev;
	uint32_t transaction_id;
	uint32_t num_ndp_instances;
	uint32_t *ndp_ids;
};

/**
 * struct nan_datapath_end_rsp_event  - firmware response to ndp end request
 * @transaction_id: unique identifier for the request
 * @status: status of operation
 * @reason: reason(opaque to host driver)
 *
 */
struct nan_datapath_end_rsp_event {
	struct wlan_objmgr_vdev *vdev;
	uint32_t transaction_id;
	uint32_t status;
	uint32_t reason;
};

/**
 * struct nan_datapath_end_indication_event - ndp termination notification from
 * FW
 * @num_ndp_ids: number of NDP ids
 * @ndp_map: mapping of NDP instances to peer and vdev
 *
 */
struct nan_datapath_end_indication_event {
	struct wlan_objmgr_vdev *vdev;
	uint32_t num_ndp_ids;
	struct peer_nan_datapath_map ndp_map[];
};

/**
 * struct nan_datapath_confirm_event - ndp confirmation event from FW
 * @vdev_id: session id of the interface over which ndp is being created
 * @ndp_instance_id: ndp instance id for which confirm is being generated
 * @reason_code : reason code(opaque to driver)
 * @num_active_ndps_on_peer: number of ndp instances on peer
 * @peer_ndi_mac_addr: peer NDI mac address
 * @rsp_code: ndp response code
 * @ndp_info: ndp application info
 *
 */
struct nan_datapath_confirm_event {
	struct wlan_objmgr_vdev *vdev;
	uint32_t ndp_instance_id;
	uint32_t reason_code;
	uint32_t num_active_ndps_on_peer;
	struct qdf_mac_addr peer_ndi_mac_addr;
	enum nan_datapath_response_code rsp_code;
	struct nan_datapath_app_info ndp_info;
};

/**
 * struct nan_datapath_indication_event - create ndp indication on the responder
 * @vdev_id: session id of the interface over which ndp is being created
 * @service_instance_id: Service identifier
 * @peer_discovery_mac_addr: Peer's discovery mac address
 * @peer_mac_addr: Peer's NDI mac address
 * @ndp_initiator_mac_addr: NDI mac address of the peer initiating NDP
 * @ndp_instance_id: locally created NDP instance ID
 * @role: self role for NDP
 * @ndp_accept_policy: accept policy configured by the upper layer
 * @ndp_config: ndp configuration params
 * @ndp_info: ndp application info
 * @ncs_sk_type: indicates NCS_SK_128 or NCS_SK_256
 * @scid: security context identifier
 *
 */
struct nan_datapath_indication_event {
	struct wlan_objmgr_vdev *vdev;
	uint32_t service_instance_id;
	struct qdf_mac_addr peer_discovery_mac_addr;
	struct qdf_mac_addr peer_mac_addr;
	uint32_t ndp_instance_id;
	enum nan_datapath_self_role role;
	enum nan_datapath_accept_policy policy;
	struct nan_datapath_cfg ndp_config;
	struct nan_datapath_app_info ndp_info;
	uint32_t ncs_sk_type;
	struct nan_datapath_scid scid;
};

/**
 * struct nan_datapath_peer_ind - ndp peer indication
 * @session_id: session id
 * @peer_mac_addr: peer mac address
 * @sta_id: station id
 *
 */
struct nan_datapath_peer_ind {
	uint8_t session_id;
	struct qdf_mac_addr peer_mac_addr;
	uint16_t sta_id;
};

/**
 * struct nan_callbacks - struct containing callback to non-converged driver
 *
 */
struct nan_callbacks {
	/* callback to os_if layer from umac */
	void (*os_if_event_handler)(struct wlan_objmgr_psoc *psoc,
				   struct wlan_objmgr_vdev *vdev,
				   uint32_t type, void *msg);

	struct wlan_objmgr_vdev* (*ndi_open)(char *iface_name);
	int (*ndi_start)(uint8_t);
	void (*ndi_close)(uint8_t);
	int (*ndi_delete)(uint8_t, char *iface_name, uint16_t transaction_id);
	void (*drv_ndi_create_rsp_handler)(uint8_t,
					struct nan_datapath_inf_create_rsp *);
	void (*drv_ndi_delete_rsp_handler)(uint8_t);

	int (*new_peer_ind)(uint8_t, uint16_t, struct qdf_mac_addr *, bool);
	int (*get_peer_idx)(uint8_t, struct qdf_mac_addr *);
	QDF_STATUS (*add_ndi_peer)(uint32_t, struct qdf_mac_addr);

	void (*peer_departed_ind)(uint8_t, uint16_t, struct qdf_mac_addr *,
				  bool);
	void (*ndp_delete_peers)(struct peer_nan_datapath_map*, uint8_t);
	void (*delete_peers_by_addr)(uint8_t, struct qdf_mac_addr);
};

#endif
#endif /* WLAN_FEATURE_NAN_CONVERGENCE */
