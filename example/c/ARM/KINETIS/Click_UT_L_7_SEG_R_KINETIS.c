/*
Example for UT_L_7_SEG_R Click

    Date          : May 2018.
    Author        : Nenad Filipovic

Test configuration KINETIS :
    
    MCU              : MK64
    Dev. Board       : HEXIWEAR
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes CS pin as OUTPUT and PWM pin as OUTPUT.
- Application Initialization - Initializes Driver enable's the displays of the UT-L 7-SEG R click.
- Application Task - (code snippet) This example shows count from 00 to 99 on the displays of the UT-L 7-SEG R click.

*/

#include "Click_UT_L_7_SEG_R_types.h"
#include "Click_UT_L_7_SEG_R_config.h"

void systemInit()
{
     mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_OUTPUT );
     mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );

     mikrobus_spiInit( _MIKROBUS1, &_UTL7SEGR_SPI_CFG[0] );

     Delay_100ms();
}

void applicationInit()
{
     utl7segr_spiDriverInit( (T_UTL7SEGR_P)&_MIKROBUS1_GPIO, (T_UTL7SEGR_P)&_MIKROBUS1_SPI );

}

void applicationTask()
{
    uint16_t counter;

    utl7segr_displayOn();
    
    utl7segr_writeData( 0x38 ); // L
    utl7segr_writeData( 0xF1 ); // F.
    Delay_1sec();

    counter = 0;
    while ( counter < 100 )
    {
        utl7segr_writeLeftNumberDot( counter );
        counter++;
        Delay_100ms();
    }
    
    Delay_1sec();
    utl7segr_writeData( 0xB8 ); // L.
    utl7segr_writeData( 0x71 ); // F
    Delay_1sec();
    
    counter = 0;
    while ( counter < 100 )
    {
        utl7segr_writeRightNumberDot( counter );
        counter++;
        Delay_100ms();
    }

    Delay_1sec();
    utl7segr_writeData( 0x79 ); // E
    utl7segr_writeData( 0x5E ); // D
    Delay_1sec();
    
    counter = 0;
    while ( counter < 100 )
    {
        utl7segr_writeDecNumber( counter );
        counter++;
        Delay_100ms();
    }
    
    Delay_1sec();
    utl7segr_writeData( 0x79 ); // E
    utl7segr_writeData( 0x76 ); // H
    Delay_1sec();

    counter = 0;
    while ( counter < 256 )
    {
        utl7segr_writeHexNumber( counter );
        counter++;
        Delay_100ms();
    }
    
    Delay_1sec();
    utl7segr_displayOff();
    Delay_1sec();
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}