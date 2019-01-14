/*
    __utl7segr_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __utl7segr_driver.h
@brief    UT_L_7_SEG_R Driver
@mainpage UT_L_7_SEG_R Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   UTL7SEGR
@brief      UT_L_7_SEG_R Click Driver
@{

| Global Library Prefix | **UTL7SEGR** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **May 2018.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _UTL7SEGR_H_
#define _UTL7SEGR_H_

/** 
 * @macro T_UTL7SEGR_P
 * @brief Driver Abstract type 
 */
#define T_UTL7SEGR_P    const uint8_t*

/** @defgroup UTL7SEGR_COMPILE Compilation Config */              /** @{ */

#define   __UTL7SEGR_DRV_SPI__                            /**<     @macro __UTL7SEGR_DRV_SPI__  @brief SPI driver selector */
//  #define   __UTL7SEGR_DRV_I2C__                            /**<     @macro __UTL7SEGR_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __UTL7SEGR_DRV_UART__                           /**<     @macro __UTL7SEGR_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup UTL7SEGR_VAR Variables */                           /** @{ */



                                                                       /** @} */
/** @defgroup UTL7SEGR_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup UTL7SEGR_INIT Driver Initialization */              /** @{ */

#ifdef   __UTL7SEGR_DRV_SPI__
void utl7segr_spiDriverInit(T_UTL7SEGR_P gpioObj, T_UTL7SEGR_P spiObj);
#endif
#ifdef   __UTL7SEGR_DRV_I2C__
void utl7segr_i2cDriverInit(T_UTL7SEGR_P gpioObj, T_UTL7SEGR_P i2cObj, uint8_t slave);
#endif
#ifdef   __UTL7SEGR_DRV_UART__
void utl7segr_uartDriverInit(T_UTL7SEGR_P gpioObj, T_UTL7SEGR_P uartObj);
#endif
                                                                       /** @} */
/** @defgroup UTL7SEGR_FUNC Driver Functions */                   /** @{ */

/**
  * @brief Write number on display

  * @param[in] writeData   Number to write

  * Generic write function
*/
void utl7segr_writeData(uint8_t wData);

/**
  * @brief Display ON

  * Function enable seven segment display.
*/
void utl7segr_displayOn();

/**
  * @brief Display OFF

  * Function disabled seven segment display.
*/
void utl7segr_displayOff();

/**
  * @brief Write two digit number

  * @param[in] number     Number to write

  * Function write decimal number from 99 to 0 on seven segment display.
*/
void  utl7segr_writeDecNumber(uint8_t number);

/**
  * @brief Write single digit float number

  * @param[in] number Number to write

  * Function write float number from 9.9 to 0.0 on seven segment display.
*/
void utl7segr_writeLeftNumberDot(uint8_t number);

/**
  * @brief Write two digit float number

  * @param[in] number     Number to write

  * Function write float number from 99. to 0.0 on seven segment display.
*/
void utl7segr_writeRightNumberDot(uint8_t number);

/**
  * @brief Write two digit hex number

  * @param[in] number     Number written as hex number

  * Function write hexadecimal number from 0 to FF on seven segment display.
*/
void utl7segr_writeHexNumber(uint16_t number);

                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_UT_L_7_SEG_R_STM.c
    @example Click_UT_L_7_SEG_R_TIVA.c
    @example Click_UT_L_7_SEG_R_CEC.c
    @example Click_UT_L_7_SEG_R_KINETIS.c
    @example Click_UT_L_7_SEG_R_MSP.c
    @example Click_UT_L_7_SEG_R_PIC.c
    @example Click_UT_L_7_SEG_R_PIC32.c
    @example Click_UT_L_7_SEG_R_DSPIC.c
    @example Click_UT_L_7_SEG_R_AVR.c
    @example Click_UT_L_7_SEG_R_FT90x.c
    @example Click_UT_L_7_SEG_R_STM.mbas
    @example Click_UT_L_7_SEG_R_TIVA.mbas
    @example Click_UT_L_7_SEG_R_CEC.mbas
    @example Click_UT_L_7_SEG_R_KINETIS.mbas
    @example Click_UT_L_7_SEG_R_MSP.mbas
    @example Click_UT_L_7_SEG_R_PIC.mbas
    @example Click_UT_L_7_SEG_R_PIC32.mbas
    @example Click_UT_L_7_SEG_R_DSPIC.mbas
    @example Click_UT_L_7_SEG_R_AVR.mbas
    @example Click_UT_L_7_SEG_R_FT90x.mbas
    @example Click_UT_L_7_SEG_R_STM.mpas
    @example Click_UT_L_7_SEG_R_TIVA.mpas
    @example Click_UT_L_7_SEG_R_CEC.mpas
    @example Click_UT_L_7_SEG_R_KINETIS.mpas
    @example Click_UT_L_7_SEG_R_MSP.mpas
    @example Click_UT_L_7_SEG_R_PIC.mpas
    @example Click_UT_L_7_SEG_R_PIC32.mpas
    @example Click_UT_L_7_SEG_R_DSPIC.mpas
    @example Click_UT_L_7_SEG_R_AVR.mpas
    @example Click_UT_L_7_SEG_R_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __utl7segr_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */