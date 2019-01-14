![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# UT_L_7_SEG_R Click

- **CIC Prefix**  : UTL7SEGR
- **Author**      : Nenad Filipovic
- **Verison**     : 1.0.0
- **Date**        : May 2018.

---

### Software Support

We provide a library for the UT_L_7_SEG_R Click on our [LibStock](https://libstock.mikroe.com/projects/view/2144/ut-l-7-seg-r-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library covers all the necessary functions for UT-L 7SEG R click control.

Key functions :

- ```utl7segr_writeDecNumber(uint8_t number);  ``` - Function write decimal number.
- ```utl7segr_writeLeftNumberDot(uint8_t number);  ``` - Function write single digit float number.
- ```utl7segr_writeRightNumberDot(uint8_t number);  ``` - Function write two digit float number.
- ```utl7segr_writeHexNumber(uint16_t number);  ``` - Function write two digit hexadecimal number.

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes CS pin as OUTPUT and PWM pin as OUTPUT.
- Application Initialization - Initializes Driver enable's the displays of the UT-L 7-SEG R click.
- Application Task - (code snippet) This example shows count and write on seven segment display float number ( from 0.0 to 99. ) , decimal number ( from 0 to 99 ) and hexadecimal number ( from 0 to FF ) .


```.c
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
```


The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2144/ut-l-7-seg-r-click) page.

Other mikroE Libraries used in the example:

- SPI Library

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
