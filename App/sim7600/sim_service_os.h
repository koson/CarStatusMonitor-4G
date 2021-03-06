/**
  ******************************************************************************
  * @file    cellular_service_os.h
  * @author  MCD Application Team
  * @brief   Header for cellular_service_os.c module
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2018 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                      http://www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef CELLULAR_SERVICE_OS_H
#define CELLULAR_SERVICE_OS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
 #include "sim_service.h"

/* Exported constants --------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* External variables --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
typedef int socket_handle_t;

#define CST_DEFAULT_PARAMA_NB    12U
#define CST_NFMC_BOOL_SIZE        2
#define CST_NFMC_VALUES_SIZE      6
#define CST_NFMC_TEMPO_NB         7U
#define CST_PDN_ACTIVATE_RETRY_DELAY 30000U
#define CST_NETWORK_STATUS_DELAY     25000U


#define CST_POWER_ON_RESET_MAX      5U
#define CST_RESET_MAX               5U
#define CST_INIT_MODEM_RESET_MAX    5U
#define CST_CSQ_MODEM_RESET_MAX     5U
#define CST_GNS_MODEM_RESET_MAX     5U
#define CST_ATTACH_RESET_MAX        5U
#define CST_DEFINE_PDN_RESET_MAX    5U
#define CST_ACTIVATE_PDN_RESET_MAX  5U
#define CST_CELLULAR_DATA_RETRY_MAX 5U
#define CST_GLOBAL_RETRY_MAX        5U

typedef struct
{
  uint32_t  active;
  uint32_t  value[CST_NFMC_TEMPO_NB];
  uint32_t  tempo[CST_NFMC_TEMPO_NB];
} CST_nfmc_context_t;

/* Exported functions ------------------------------------------------------- */
/* Cellular Service Library Init */
CS_Bool_t osCDS_cellular_service_init(void);

CS_Status_t osCS_get_signal_quality(CS_SignalQuality_t *p_sig_qual);

/* SOCKET API */
socket_handle_t osCDS_socket_create(CS_TransportProtocol_t protocol);

//CS_Status_t osCDS_socket_set_callbacks(socket_handle_t sockHandle, cellular_socket_data_ready_callback_t data_ready_cb,                                     cellular_socket_data_sent_callback_t data_sent_cb,                                       cellular_socket_closed_callback_t remote_close_cb);

CS_Status_t osCDS_socket_set_option(void);

CS_Status_t osCDS_socket_get_option(void);

CS_Status_t osCDS_socket_bind(socket_handle_t sockHandle,
                              uint16_t local_port);

CS_Status_t osCDS_socket_connect( CS_CHAR_t *p_ip_addr_value,  uint16_t remote_port); /* for socket client mode */

CS_Status_t osCDS_socket_listen(void);

CS_Status_t osCDS_socket_send( const CS_CHAR_t *p_buf,       uint32_t length);

int32_t osCDS_socket_receive(     CS_CHAR_t *p_buf,          uint32_t max_buf_length);

CS_Status_t osCDS_socket_cnx_status(socket_handle_t sockHandle,  CS_SocketCnxInfos_t *infos);

CS_Status_t osCDS_socket_close(socket_handle_t sockHandle,     uint8_t force);

/* =========================================================
   ===========      Mode Command services        ===========
   ========================================================= */
CS_Status_t osCDS_get_net_status(CS_RegistrationStatus_t *p_reg_status);
CS_Status_t osCDS_get_device_info(CS_DeviceInfo_t *p_devinfo);
CS_Status_t osCDS_subscribe_net_event(CS_UrcEvent_t event,
                                      cellular_urc_callback_t urc_callback);
CS_Status_t osCDS_subscribe_modem_event(CS_ModemEvent_t events_mask,
                                        cellular_modem_event_callback_t modem_evt_cb);
CS_Status_t osCDS_power_on(void);
CS_Status_t osCDS_reset(CS_Reset_t rst_type);
CS_Status_t osCDS_init_modem( CS_Bool_t reset,const char *pin_code);
CS_Status_t osCDS_register_net(CS_OperatorSelector_t *p_operator,CS_RegistrationStatus_t *p_reg_status);
CS_Status_t osCDS_get_attach_status(CS_PSattach_t *p_attach);
CS_Status_t osCDS_attach_PS_domain(void);

CS_Status_t osCDS_define_pdn(uint8_t cid, const char *apn, uint8_t *pdptype);
CS_Status_t osCDS_register_pdn_event(uint8_t cid,cellular_pdn_event_callback_t pdn_event_callback);
CS_Status_t osCDS_set_default_pdn(uint8_t cid);
CS_Status_t osCDS_activate_pdn(uint8_t cid);

CS_Status_t osCDS_suspend_data(void);
CS_Status_t osCDS_resume_data(void);
CST_state_t CST_get_state(void);


//CS_Status_t osCDS_dns_request(uint8_t cid, CS_DnsReq_t  *dns_req, CS_DnsResp_t *dns_resp);

//CS_Status_t osCDS_ping(uint8_t cid, CS_Ping_params_t *ping_params, cellular_ping_response_callback_t cs_ping_rsp_cb);

#ifdef __cplusplus
}
#endif

#endif /* CELLULAR_SERVICE_OS_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
