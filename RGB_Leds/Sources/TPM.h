/**********************************************************************************************//*!
 *
 * @file UART.h
 *
 * @author B22385
 *
 * @date Dec 21, 2012
 *
 * @brief 
 *************************************************************************************************/

#ifndef TPM_H_
#define TPM_H_



/*************************************************************************************************/
/*                                      Includes Section                                         */
/*************************************************************************************************/

/*************************************************************************************************/
/*                                  Defines & Macros Section                                     */
/*************************************************************************************************/

enum eTPM
{
	TPM0 = 0,
	TPM1,
	TPM2,
	MAX_TPM
};

enum eTPMChannel
{
	TPM_CH0 = 0,
	TPM_CH1,
	TPM_CH2,
	TPM_CH3,
	TPM_CH4,
	TPM_CH5
};

enum eTPMSourceCLK
{
	TPM_DISABLED = 0,
	TPM_CLK_FLL_PLL = 1,
	TPM_CLK_OSC,
	TPM_CLK_IRC
};

enum eTPMMSBMSA
{
	TPM_MSB_MSA_00 = 0,
	TPM_MSB_MSA_01,
	TPM_MSB_MSA_10,
	TPM_MSB_MSA_11,
};

enum eTPMELSBELSA
{
	TPM_ELSB_ELSA_00 = 0,
	TPM_ELSB_ELSA_01,
	TPM_ELSB_ELSA_10,
	TPM_ELSB_ELSA_11,
};


enum eTPMPrescaler
{
	TPM_PRESCALER_1 = 0,
	TPM_PRESCALER_2,
	TPM_PRESCALER_4,
	TPM_PRESCALER_8,
	TPM_PRESCALER_16,
	TPM_PRESCALER_32,
	TPM_PRESCALER_64,
	TPM_PRESCALER_128
};
/*************************************************************************************************/
/*                                      Typedef Section                                          */
/*************************************************************************************************/


/*************************************************************************************************/
/*                                Function-like Macros Section                                   */
/*************************************************************************************************/
#define TPM_APPLICATION_PRESCALER	(TPM_PRESCALER_32)
/*************************************************************************************************/
/*                                  Extern Constants Section                                     */
/*************************************************************************************************/

/*************************************************************************************************/
/*                                  Extern Variables Section                                     */
/*************************************************************************************************/

/*************************************************************************************************/
/*                                Function Prototypes Section                                    */
/*************************************************************************************************/
void TPM_vfnInit(uint8_t bTPMToEnable, uint8_t bTPMClockSource, uint16_t wTPMModulo);
void TPM_vfnStartTimer(uint8_t bTPMToEnable, uint8_t bTPMPrescaler);
void TPM_vfnConfigChannel(uint8_t bTPMToEnable, uint8_t bTPMChannel, uint8_t bTPMMSx, uint8_t bTPMELSx, uint16_t wChannelValue);
void TPM_vfnUpdateChannel(uint8_t bTPMToEnable, uint8_t bTPMChannel, uint16_t wChannelValue);
/*************************************************************************************************/

#endif /* TPM_H_ */
