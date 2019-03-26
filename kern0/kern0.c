#include <stdint.h>
static volatile char *VGABUF = (volatile char *) 0xb8000;

static void vga_write(const char *s, int8_t linea, uint8_t color) {
	int pos = (linea * 160);
	VGABUF += pos;
	volatile char *buf = VGABUF;
	
	while( *s != 0 ) {
        *buf++ = *s++;
        *buf++ = color;
    }
}

void comienzo(void) {
    const char *s1 = "OK";
    uint8_t color1 = 47;
    
    vga_write(s1, 0, color1);
    
    const char *s2 = "HOLA";
    uint8_t color2 = 224;
    
    vga_write(s2, 1, color2);

    while (1)
        asm("hlt");
}
