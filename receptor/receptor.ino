#include <VirtualWire.h>
 
const int dataPin = 12;
 
void setup()
{
    Serial.begin(9600);
    vw_setup(2000);
    vw_set_rx_pin(dataPin);
    vw_rx_start();
}
 
void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
 
   // Recibir dato
    if (vw_get_message((uint8_t *)buf,&buflen))
    {
      String dataString;
        if((char)buf[0]=='z')
        {
            for (int i = 1; i < buflen; i++)
            {
            dataString.concat((char)buf[i]);
            }
            int a = dataString.toInt();  // Convertir a int
            
        }
        if((char)buf[0]=='x')
        {
            for (int i = 1; i < buflen; i++)
            {
            dataString.concat((char)buf[i]);
            }
            int b = dataString.toInt();  // Convertir a int
            
        }
        if((char)buf[0]=='c')
        {
            for (int i = 1; i < buflen; i++)
            {
            dataString.concat((char)buf[i]);
            }
            int c = dataString.toInt();  // Convertir a int
            
        }
        if((char)buf[0]=='d')
        {
            for (int i = 1; i < buflen; i++)
            {
            dataString.concat((char)buf[i]);
            }
            int d = dataString.toInt();  // Convertir a int
            
        }
        if((char)buf[0]=='x')
        {
            for (int i = 1; i < buflen; i++)
            {
            dataString.concat((char)buf[i]);
            }
            int x = dataString.toInt();  // Convertir a int
          Serial.print(x);Serial.print('\t');
         
           
        }
        if((char)buf[0]=='y')
        {
            for (int i = 1; i < buflen; i++)
            {
            dataString.concat((char)buf[i]);
            }
            int y = dataString.toInt();  // Convertir a int
          Serial.print(y);Serial.print('\t');
         
        
        }
        if((char)buf[0]=='z')
        {
            for (int i = 1; i < buflen; i++)
            {
            dataString.concat((char)buf[i]);
            }
            int z = dataString.toInt();  // Convertir a int
        
          Serial.println(z);    
         
        }
        
    }
}
