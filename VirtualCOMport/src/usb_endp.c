/********************************************************************************
  * @file    usb_endp.c
  * @author  MCD Application Team
  * @version V3.4.0
  * @date    29-June-2012
  * @brief   Endpoint routines
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "usb_lib.h"
#include "usb_desc.h"
#include "usb_mem.h"
//#include "hw_config.h"
#include "usb_istr.h"
#include "usb_pwr.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Interval between sending IN packets in frame number (1 frame = 1ms) */
#define VCOMPORT_IN_FRAME_INTERVAL             5

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint8_t USB_Rx_Buffer[VIRTUAL_COM_PORT_DATA_SIZE];
//extern  uint8_t USART_Rx_Buffer[];
//extern uint32_t USART_Rx_ptr_out;
//extern uint32_t USART_Rx_length;
//extern uint8_t  USB_Tx_State;
u32 count_out = 0;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : EP1_IN_Callback
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void EP1_IN_Callback (void)
{
//  uint16_t USB_Tx_ptr;
//  uint16_t USB_Tx_length;
//  
//  if (USB_Tx_State == 1)
//  {
//    if (USART_Rx_length == 0) 
//    {
//      USB_Tx_State = 0;
//    }
//    else 
//    {
//      if (USART_Rx_length > VIRTUAL_COM_PORT_DATA_SIZE){
//        USB_Tx_ptr = USART_Rx_ptr_out;
//        USB_Tx_length = VIRTUAL_COM_PORT_DATA_SIZE;
//        
//        USART_Rx_ptr_out += VIRTUAL_COM_PORT_DATA_SIZE;
//        USART_Rx_length -= VIRTUAL_COM_PORT_DATA_SIZE;    
//      }
//      else 
//      {
//        USB_Tx_ptr = USART_Rx_ptr_out;
//        USB_Tx_length = USART_Rx_length;
//        
//        USART_Rx_ptr_out += USART_Rx_length;
//        USART_Rx_length = 0;
//      }
//      
//#ifdef USE_STM3210C_EVAL
//      USB_SIL_Write(EP1_IN, &USART_Rx_Buffer[USB_Tx_ptr], USB_Tx_length);  
//#else
//      UserToPMABufferCopy(&USART_Rx_Buffer[USB_Tx_ptr], ENDP1_TXADDR, USB_Tx_length);
//      SetEPTxCount(ENDP1, USB_Tx_length);
//      SetEPTxValid(ENDP1); 
//#endif  
//    }
//  }
}

/*******************************************************************************
* Function Name  : EP3_OUT_Callback
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void EP3_OUT_Callback(void)
{
  //uint16_t USB_Rx_Cnt;
  
  /* Get the received data buffer and update the counter */
  //USB_Rx_Cnt = USB_SIL_Read(EP3_OUT, USB_Rx_Buffer);
  
  /* USB data will be immediately processed, this allow next USB traffic being 
  NAKed till the end of the USART Xfer */
  
  //USB_To_USART_Send_Data(USB_Rx_Buffer, USB_Rx_Cnt);

	//count_out = GetEPRxCount(ENDP3);
	count_out = USB_SIL_Read(EP3_OUT, USB_Rx_Buffer);
  //PMAToUserBufferCopy(USB_Rx_Buffer, ENDP3_RXADDR, count_out); // Copy a buffer from packet memory area (PMA) to user memory area, Hari
  //SetEPRxValid(ENDP3);
	
#ifndef STM32F10X_CL
  /* Enable the receive of data on EP3 */
  SetEPRxValid(ENDP3);
#endif /* STM32F10X_CL */
}


/*******************************************************************************
* Function Name  : SOF_Callback / INTR_SOFINTR_Callback
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
#ifdef STM32F10X_CL
void INTR_SOFINTR_Callback(void)
#else
void SOF_Callback(void)
#endif /* STM32F10X_CL */
{
//  static uint32_t FrameCount = 0;
//  
//  if(bDeviceState == CONFIGURED)
//  {
//    if (FrameCount++ == VCOMPORT_IN_FRAME_INTERVAL)
//    {
//      /* Reset the frame counter */
//      FrameCount = 0;
//      
//      /* Check the data to be sent through IN pipe */
//      Handle_USBAsynchXfer();
//    }
//  }  
}
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

