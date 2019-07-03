#ifndef DRV8833MODULE_H
#define DRV8833MODULE_H

#include "Arduino.h"

class drv8833 {
   public:
      // Constructor method:
      drv8833(uint8_t a1, uint8_t a2, uint8_t b1, uint8_t b2);

      // Init method:
      void init(void);
      
      // The cover-all function:   
      void speeds(int left, int right);
      
      // Utilize the speeds function:
      void forward(uint8_t speed);
      void back(uint8_t speed);

      // Stop uses double low to stop the motors,
      // hardstop uses double high.
      void stop(void);
      void hardstop(void);

   private:

      // Input pins, used to address the driver:
      uint8_t ina1;
      uint8_t ina2;
      uint8_t inb1;
      uint8_t inb2;

      // Fault and sleep pins, not always initialized.
      uint8_t sleeppin;
      uint8_t faultpin;

};

#endif /*DRV8833MODULE_H*/
