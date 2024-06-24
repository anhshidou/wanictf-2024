#include<stdio.h>
#include <stdbool.h>
#include <string.h>
unsigned char data[] = {
    0xB2, 0x03, 0x00, 0x00, 0xA4, 0x03, 0x00, 0x00,
    0xB8, 0x03, 0x00, 0x00, 0xAA, 0x03, 0x00, 0x00,
    0xC0, 0x03, 0x00, 0x00, 0xA4, 0x03, 0x00, 0x00,
    0xD4, 0x03, 0x00, 0x00, 0xC2, 0x03, 0x00, 0x00,
    0xF0, 0x03, 0x00, 0x00, 0xE4, 0x03, 0x00, 0x00,
    0xD8, 0x03, 0x00, 0x00, 0xE0, 0x03, 0x00, 0x00,
    0xE8, 0x03, 0x00, 0x00, 0x32, 0x02, 0x00, 0x00,
    0xC4, 0x03, 0x00, 0x00, 0x36, 0x02, 0x00, 0x00,
    0xE0, 0x03, 0x00, 0x00, 0xCE, 0x03, 0x00, 0x00,
    0xD0, 0x03, 0x00, 0x00, 0x30, 0x02, 0x00, 0x00,
    0xD8, 0x03, 0x00, 0x00, 0xC4, 0x03, 0x00, 0x00,
    0xC8, 0x03, 0x00, 0x00, 0x2C, 0x02, 0x00, 0x00,
    0xC4, 0x03, 0x00, 0x00, 0xCE, 0x03, 0x00, 0x00,
    0xA2, 0x03, 0x00, 0x00, 0xDC, 0x03, 0x00, 0x00,
    0xF0, 0x03, 0x00, 0x00, 0x10, 0x02, 0x00, 0x00,
    0xDA, 0x03, 0x00, 0x00, 0xE8, 0x03, 0x00, 0x00,
    0x2C, 0x02, 0x00, 0x00, 0x38, 0x02, 0x00, 0x00,
    0xD8, 0x03, 0x00, 0x00, 0x1E, 0x02, 0x00, 0x00,
    0xD6, 0x03, 0x00, 0x00, 0x32, 0x02, 0x00, 0x00,
    0xEE, 0x03, 0x00, 0x00, 0x3C, 0x02, 0x00, 0x00,
    0x3C, 0x02, 0x00, 0x00, 0x84, 0x03, 0x00, 0x00,
    0x70, 0x02, 0x00, 0x00, 0x68, 0x03, 0x00, 0x00
};

int main(){
  bool bVar1;
  int local_128;
  int local_124;
  int local_120;
  int local_11c;
  int local_118 [44];
  char acStack_68 [55];
  char local_31;
  int x;
  int y;

  memcpy(local_118,data,0xb0);
  local_11c = 0;
  local_128 = 0x7c46699a;
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          while( true ) {
            while( true ) {
              while( true ) {
                while( true ) {
                  while( true ) {
                    while( true ) {
                      while (local_128 == -0x5ddba386) {
                        local_124 = local_124 + 1;
                        bVar1 = (x * (x + -1) & 1U) == 0;
                        local_128 = 0x60b926fc;
                        if (bVar1 && y < 10 || bVar1 != y < 10) {
                          local_128 = -0x51fc1498;
                        }
                      }
                      if (local_128 != -0x51fc1498) break;
                      local_128 = 0x19056f3d;
                    }
                    if (local_128 != -0x44e001df) break;
                    local_128 = 0x54525dca;
                    if ((local_31 & 1) != 0) {
                      local_128 = -0x1c311557;
                    }
                  }
                  if (local_128 != -0x34d6a440) break;
                  bVar1 = (x * (x + -1) & 1U) != 0;
                  local_128 = 0x58d9f831;
                  if (bVar1 != 9 < y || !bVar1 && 9 >= y) {
                    local_128 = -0x1d900a39;
                  }
                }
                if (local_128 != -0x2d337dcd) break;
                local_120 = local_120 + 1;
                local_128 = 0x694bd910;
              }
              if (local_128 != -0x2462fe04) break;
              local_128 = -0x22f9de40;
            }
            if (local_128 != -0x22f9de40) break;
            bVar1 = (x * (x + -1) & 1U) != 0;
            local_128 = 0x60b926fc;
            if (bVar1 != 9 < y || !bVar1 && 9 >= y) {
              local_128 = -0x5ddba386;
            }
          }
          if (local_128 != -0x21c3cf2d) break;
          local_31 = local_120 < 0x2c;
          bVar1 = (x * (x + -1) & 1U) == 0;
          local_128 = 0x34e86ff4;
          if (bVar1 && y < 10 || bVar1 != y < 10) {
            local_128 = -0x44e001df;
          }
        }
        if (local_128 != -0x1d900a39) break;
        acStack_68[local_124] = (char)local_118[local_124] - (char)local_124;
        bVar1 = (x * (x + -1) & 1U) == 0;
        local_128 = 0x58d9f831;
        if (bVar1 != y < 10 || bVar1 && y < 10) {
          local_128 = -0x2462fe04;
        }
      }
      if (local_128 != -0x1c311557) break;
      local_118[local_120] =
           (local_118[local_120] ^ 0xffffffff) & 0x19f | local_118[local_120] & 0xfffffe60;
      local_128 = -0x2d337dcd;
    }
    if (local_128 == 0x19341ee) break;
    if (local_128 == 0x19056f3d) {
      local_128 = 0x19341ee;
      if (local_124 < 0x2c) {
        local_128 = -0x34d6a440;
      }
    }
    else if (local_128 == 0x25d256eb) {
      local_118[local_11c] = (int)local_118[local_11c] / 2;
      local_128 = 0x299ff63b;
    }
    else if (local_128 == 0x299ff63b) {
      local_11c = local_11c + 1;
      local_128 = 0x7c46699a;
    }
    else if (local_128 == 0x33ee2572) {
      local_120 = 0;
      local_128 = 0x694bd910;
    }
    else if (local_128 == 0x34e86ff4) {
      local_128 = -0x21c3cf2d;
    }
    else if (local_128 == 0x54525dca) {
      local_124 = 0;
      local_128 = 0x19056f3d;
    }
    else if (local_128 == 0x58d9f831) {
      acStack_68[local_124] = (char)local_118[local_124] - (char)local_124;
      local_128 = -0x1d900a39;
    }
    else if (local_128 == 0x60b926fc) {
      local_124 = local_124 + 1;
      local_128 = -0x5ddba386;
    }
    else if (local_128 == 0x694bd910) {
      bVar1 = (x * (x + -1) & 1U) == 0;
      local_128 = 0x34e86ff4;
      if (bVar1 && y < 10 || bVar1 != y < 10) {
        local_128 = -0x21c3cf2d;
      }
    }
    else if ((local_128 == 0x7c46699a) && (local_128 = 0x33ee2572, local_11c < 0x2c)) {
      local_128 = 0x25d256eb;
    }
  }
  printf("Processing completed! %s", acStack_68);
  return 0;
}
