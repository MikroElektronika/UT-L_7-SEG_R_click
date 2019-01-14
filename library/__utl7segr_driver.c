/*
    __utl7segr_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__utl7segr_driver.h"
#include "__utl7segr_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __UTL7SEGR_DRV_I2C__
static uint8_t _slaveAddress;
#endif
static const uint8_t _UTM7SEGR_DOT = 0x80;

static const uint8_t NUMBERS[ 16 ] =
{
    0x3F,  // 0
    0x06,  // 1
    0x5B,  // 2
    0x4F,  // 3
    0x66,  // 4
    0x6D,  // 5
    0x7D,  // 6
    0x07,  // 7
    0x7F,  // 8
    0x6F,  // 9
    0x77,  // A
    0x7C,  // B
    0x39,  // C
    0x5E,  // D
    0x79,  // E
    0x71   // F
};

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */

/* Function return convert hex number. */
static uint8_t utl7segr_getNumber(uint8_t number)
{
     return NUMBERS[ number ];
}

/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __UTL7SEGR_DRV_SPI__

void utl7segr_spiDriverInit(T_UTL7SEGR_P gpioObj, T_UTL7SEGR_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    hal_gpio_csSet(1);
    hal_gpio_pwmSet(1);
}

#endif
#ifdef   __UTL7SEGR_DRV_I2C__

void utl7segr_i2cDriverInit(T_UTL7SEGR_P gpioObj, T_UTL7SEGR_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __UTL7SEGR_DRV_UART__

void utl7segr_uartDriverInit(T_UTL7SEGR_P gpioObj, T_UTL7SEGR_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif

/* ----------------------------------------------------------- IMPLEMENTATION */

/* Function will write number on seven segment display. */
void utl7segr_writeData(uint8_t wData)
{
    char buff[ 2 ];
    buff[ 0 ] = wData;

    hal_gpio_csSet( 0 );
    hal_spiTransfer( buff, buff, 1 );
    hal_gpio_csSet( 1 );
}

/* Function enable seven segment display with PMW. */
void utl7segr_displayOn()
{
    hal_gpio_pwmSet( 1 );
}

/* Function disabled seven segment display with PMW. */
void utl7segr_displayOff()
{
    hal_gpio_pwmSet( 0 );
}

/* Function write decimal number from 0 to 99 on seven segment display. */
void utl7segr_writeDecNumber(uint8_t number)
{
    uint8_t rightNumber;
    uint8_t leftNumber;
      
    number %= 100;

    leftNumber = number / 10;
    rightNumber = number % 10;
      
    utl7segr_writeData( 0 );
    utl7segr_writeData( 0 );
      
    if ( leftNumber < 1 )
    {
        utl7segr_writeData( utl7segr_getNumber( rightNumber ) );
        utl7segr_writeData( 0 );
    }
    else
    {
        utl7segr_writeData( utl7segr_getNumber( rightNumber ) );
        utl7segr_writeData( utl7segr_getNumber( leftNumber ) );
    }
}
/* Function write float number from 0.0 to 9.9 on seven segment display. */
void utl7segr_writeLeftNumberDot(uint8_t number)
{
    uint8_t rightNumber;
    uint8_t leftNumber;

    number %= 100;

    leftNumber = number / 10;
    rightNumber = number % 10;

    utl7segr_writeData( 0 );
    utl7segr_writeData( 0 );

    utl7segr_writeData( utl7segr_getNumber( rightNumber ) );
    utl7segr_writeData( utl7segr_getNumber( leftNumber ) | _UTM7SEGR_DOT );
}

/* Function write float number from 1. to 99. on seven segment display. */
void utl7segr_writeRightNumberDot(uint8_t number)
{
    uint8_t rightNumber;
    uint8_t leftNumber;

    number %= 100;

    leftNumber = number / 10;
    rightNumber = number % 10;

    utl7segr_writeData( 0 );
    utl7segr_writeData( 0 );

    if ( leftNumber < 1 )
    {
        utl7segr_writeData( utl7segr_getNumber(rightNumber) | _UTM7SEGR_DOT );
        utl7segr_writeData( 0 );
    }
    else
    {
        utl7segr_writeData( utl7segr_getNumber( rightNumber) | _UTM7SEGR_DOT );
        utl7segr_writeData( utl7segr_getNumber( leftNumber ) );
    }
}

/* Function write hexadecimal number from 1 to FF on seven segment display. */
void utl7segr_writeHexNumber(uint16_t number)
{
    uint8_t rightNumber;
    uint8_t leftNumber;

    number %= 256;

    leftNumber = number / 16;
    rightNumber = number % 16;

    utl7segr_writeData( 0 );
    utl7segr_writeData( 0 );

    if (leftNumber < 1)
    {
        utl7segr_writeData( utl7segr_getNumber( rightNumber ) );
        utl7segr_writeData( 0 );
    }
    else
    {
        utl7segr_writeData( utl7segr_getNumber( rightNumber ) );
        utl7segr_writeData( utl7segr_getNumber( leftNumber ) );
    }
}

/* -------------------------------------------------------------------------- */
/*
  __utl7segr_driver.c

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