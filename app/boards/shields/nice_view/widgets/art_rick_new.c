#include <lvgl.h>

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_RICK_000
#define LV_ATTRIBUTE_IMG_RICK_000
#endif
#ifndef LV_ATTRIBUTE_IMG_RICK_001
#define LV_ATTRIBUTE_IMG_RICK_001
#endif


const uint8_t imgCount_rick = 2;

const uint8_t color_0[2][4]={
 {0xee,0xee,0xee,0xff},
 {0xee,0xee,0xee,0xff}
};

const uint8_t color_1[2][4]={
 {0xee,0xee,0xee,0xff},
 {0xee,0xee,0xee,0xff}
};

const uint8_t *imgData[2]={
 (const uint8_t[]){0x00,139,0x0e,1,0x00,16,0x20,1,0x3e,1,0x00,16,0x5c,1,0x7f,1,0x80,1,0x00,12,0x7a,1,0x00,1,0x04,1,0xb8,1,0x7e,1,0x00,13,0x3e,1,0x00,1,0x0b,1,0x7d,1,0xff,1,0x00,12,0x40,1,0x0f,1,0xc8,1,0x1d,1,0xff,2,0x80,1,0x00,13,0xaa,1,0x7f,1,0xff,2,0x80,1,0x00,13,0x2d,1,0x7f,1,0xff,2,0xc0,1,0x00,12,0x04,1,0x57,1,0xff,3,0xc0,1,0x00,9,0x57,1,0xc0,1,0x09,1,0x2a,1,0xaf,1,0xff,3,0xe0,1,0x00,7,0x15,1,0x00,1,0xbf,1,0xe0,1,0x6e,1,0xd5,1,0x57,1,0xff,3,0xe0,1,0x00,7,0xff,1,0x42,1,0xff,1,0xfa,1,0xbf,1,0xea,1,0x2b,1,0xff,3,0xe0,1,0x00,6,0x05,1,0xfe,1,0xf5,1,0xff,3,0xfa,1,0xd7,1,0xff,2,0xf9,1,0xf0,1,0x00,6,0x5f,1,0xff,3,0xfe,1,0xff,1,0xed,1,0x57,1,0xff,2,0xf9,1,0xf8,1,0x00,5,0x01,1,0xff,10,0xf1,1,0xfc,1,0x00,3,0x10,1,0x05,1,0xf3,1,0xff,6,0xfa,1,0xab,1,0xff,3,0xfe,1,0x00,3,0xff,1,0xfc,1,0xfb,1,0xff,7,0xaf,1,0xff,4,0x02,1,0x00,2,0xff,1,0xfc,1,0xff,7,0xf5,1,0x57,1,0xff,4,0x80,1,0x00,2,0xff,1,0xfe,1,0xff,8,0x6f,1,0xff,4,0x02,1,0x00,2,0xff,7,0xfe,1,0xff,1,0xfe,1,0xab,1,0xff,3,0xfe,1,0x00,3,0xff,14,0xfc,1,0x00,3,0xff,10,0xb7,1,0xff,3,0xfe,1,0x00,3,0xff,9,0xfa,1,0xef,1,0xff,4,0x00,3,0xff,15,0x80,1,0x00,2,0xff,15,0x80,1,0x00,2,0xff,9,0xfe,1,0xff,5,0xc4,1,0x00,2,0xff,2,0xdf,1,0xff,12,0x82,1,0x00,2,0xff,2,0xbf,1,0xff,12,0xea,1,0x00,2,0xff,2,0xdf,1,0xff,12,0xd4,1,0x00,2,0xff,2,0xdf,1,0xff,12,0xf8,1,0x00,2,0xff,15,0xf8,1,0x00,2,0xff,4,0x25,1,0x7f,1,0xff,9,0xfc,1,0x00,2,0xff,1,0xfd,1,0xdf,1,0xfe,1,0x00,1,0x2f,1,0xff,3,0xfe,1,0xaf,1,0xff,4,0xfe,1,0x00,2,0x49,1,0x54,1,0xcf,1,0xf4,1,0x00,1,0x01,1,0x57,1,0xff,3,0x7f,1,0xff,4,0xfe,1,0x00,3,0x11,1,0x8f,1,0xec,1,0x00,2,0x07,1,0xff,2,0xfd,1,0x57,1,0xff,4,0xfe,1,0x00,2,0x04,1,0x21,1,0x8f,1,0xde,1,0x00,2,0x07,1,0xff,2,0xfe,1,0xaf,1,0xff,4,0xfe,1,0x00,2,0xff,2,0x85,1,0x1e,1,0x00,2,0x07,1,0xff,2,0xfd,1,0x53,1,0xff,5,0x00,2,0x45,1,0xff,1,0x84,1,0x1e,1,0x00,2,0x07,1,0xff,2,0xfe,1,0xd5,1,0xff,5,0x00,3,0x01,1,0x80,1,0x0e,1,0x00,2,0x0f,1,0xff,3,0xb5,1,0xff,5,0x80,1,0x00,1,0xff,2,0x80,1,0x1e,1,0x00,2,0x0f,1,0xff,3,0xea,1,0xff,4,0xef,1,0x00,2,0xef,1,0xf7,1,0xc0,1,0x0e,1,0x00,2,0x1f,1,0xff,1,0x55,1,0xff,1,0xf1,1,0x7f,1,0xff,3,0xe7,1,0xc0,1,0x00,1,0x5f,1,0xeb,1,0x80,1,0x1c,1,0x00,2,0x3f,1,0xfd,1,0x5b,1,0xff,1,0xd4,1,0x7f,1,0xff,3,0xfb,1,0xa0,1,0x00,1,0x8f,1,0xd3,1,0x80,1,0x08,1,0x00,2,0x7f,1,0xfe,1,0xaa,1,0xff,1,0xa9,1,0x7f,1,0xff,3,0xfa,1,0xc0,1,0x00,1,0x17,1,0xab,1,0x80,1,0x10,1,0x00,2,0xff,1,0xfa,1,0x55,1,0xaa,1,0xa0,1,0x3f,1,0xff,4,0x80,1,0x00,1,0x0a,1,0xa1,1,0x80,1,0x00,1,0x50,1,0x03,1,0xff,1,0xfc,1,0xa1,1,0x75,1,0x40,1,0x3f,1,0xff,4,0x80,1,0x00,1,0x17,1,0x41,1,0x80,1,0x15,1,0xf4,1,0x03,1,0xff,1,0xf8,1,0x00,1,0x8a,1,0x00,1,0x3f,1,0xff,4,0x80,1,0x00,1,0x0a,1,0x81,1,0x80,1,0x0f,1,0xf8,1,0x07,1,0xff,1,0xf8,1,0x00,1,0x28,1,0x00,1,0x3f,1,0xff,4,0xc0,1,0x00,1,0x15,1,0x01,1,0x80,1,0x1f,1,0xf5,1,0x07,1,0xff,1,0xf8,1,0x00,3,0x1f,1,0xff,3,0xef,1,0x80,1,0x00,1,0x05,1,0x41,1,0xc0,1,0x1f,1,0xfa,1,0x0f,1,0xff,1,0xf8,1,0x00,1,0x14,1,0x00,1,0x3f,1,0xff,4,0x00,2,0x50,1,0x01,1,0xe0,1,0x3f,1,0xf5,1,0x5f,1,0xff,1,0xf8,1,0x00,3,0x1f,1,0xff,3,0xee,1,0x80,1,0x00,1,0x05,1,0x03,1,0xe8,1,0x7f,1,0xaa,1,0xab,1,0xff,1,0xf8,1,0x00,3,0x1f,1,0xff,3,0xef,1,0x00,3,0x07,1,0xf0,1,0x7f,1,0xea,1,0xaf,1,0xff,1,0xf8,1,0x00,3,0x0f,1,0xff,3,0xea,1,0x00,3,0x0f,1,0xe0,1,0xfa,1,0xaa,1,0xb5,1,0xff,1,0xf8,1,0x00,3,0x17,1,0xff,3,0xea,1,0x00,3,0x0f,1,0xe2,1,0xed,1,0x55,1,0x6b,1,0xff,1,0xf8,1,0x00,3,0x0f,1,0xff,3,0xfe,1,0x00,3,0x1f,1,0xc1,1,0xaa,1,0x82,1,0x8a,1,0xfb,1,0xf8,1,0x00,3,0x07,1,0xff,3,0xfd,1,0x00,3,0x1f,1,0x83,1,0x54,1,0x28,1,0x21,1,0xf5,1,0xf8,1,0x00,3,0x07,1,0xff,1,0xfe,1,0xff,1,0xfc,1,0x00,3,0x2a,1,0x0a,1,0x81,1,0x42,1,0x00,1,0xf3,1,0xf0,1,0x00,3,0x07,1,0xff,2,0x79,1,0xfa,1,0x00,5,0x04,1,0x00,2,0x71,1,0xf0,1,0x00,3,0x03,1,0xff,2,0xf7,1,0xe8,1,0x00,8,0x01,1,0xf0,1,0x00,3,0x03,1,0xff,3,0xf0,1,0x00,8,0x21,1,0xe0,1,0x00,3,0x03,1,0xff,3,0xea,1,0x00,8,0x01,1,0xe0,1,0x00,3,0x03,1,0xff,3,0xf0,1,0x00,2},
 (const uint8_t[]){0x00,140,0x80,1,0x00,16,0x07,1,0xc0,1,0x00,16,0x17,1,0xc0,1,0x00,16,0x7f,1,0xe0,1,0x00,15,0x15,1,0xff,1,0xf0,1,0x00,15,0x7f,1,0xff,1,0xf0,1,0x00,14,0x01,1,0xff,2,0xf0,1,0x00,14,0x27,1,0xff,2,0xf8,1,0x00,14,0x1f,1,0xff,2,0xbc,1,0x00,10,0x14,1,0x00,3,0x5f,1,0xff,2,0x1c,1,0x00,9,0x03,1,0xfe,1,0x00,1,0x40,1,0x00,1,0x3f,1,0xff,2,0x7e,1,0x00,7,0x01,1,0x40,1,0x05,1,0xff,1,0x45,1,0x54,1,0x00,1,0xff,4,0x00,7,0x0f,1,0xf5,1,0x0b,1,0xff,1,0xfb,2,0x53,1,0xff,4,0x80,1,0x00,6,0xaf,1,0xdf,1,0xff,2,0xaf,1,0xfd,1,0x55,1,0xff,4,0xc0,1,0x00,5,0x0b,1,0x7f,1,0xff,3,0xfb,1,0xf7,1,0xfb,1,0xff,4,0xc0,1,0x00,5,0xff,1,0xbf,1,0xff,4,0xfd,1,0x55,1,0xff,4,0xc0,1,0x00,2,0x11,1,0x00,1,0xf3,1,0xff,7,0xfd,1,0xff,4,0x80,1,0x00,2,0xff,1,0x6c,1,0xfb,1,0xff,6,0xf5,1,0x57,1,0xff,4,0x80,1,0x00,2,0xff,1,0xfe,1,0xff,8,0xfa,1,0xff,4,0xc0,1,0x00,2,0xff,1,0xfe,1,0xff,8,0xab,1,0xff,4,0xc0,1,0x00,2,0xff,4,0xf2,1,0xff,10,0xe0,1,0x00,2,0xff,4,0xe1,1,0x7f,1,0xff,4,0xfb,1,0xff,4,0xf0,1,0x00,2,0xff,1,0x7f,1,0xff,2,0xf4,1,0xff,5,0x7f,1,0xff,4,0xf0,1,0x00,2,0xff,4,0xfb,1,0xff,5,0xf7,1,0xff,4,0xf0,1,0x00,2,0xff,15,0xf0,1,0x00,2,0xff,2,0xdf,1,0xff,13,0x00,2,0xff,2,0xdf,1,0xff,1,0xea,1,0xbf,1,0xff,10,0x00,2,0xff,2,0xdf,1,0xff,1,0xd5,1,0x57,1,0xff,10,0x80,1,0x00,1,0xff,2,0x9f,1,0xff,1,0xa0,1,0x15,1,0xff,10,0x80,1,0x00,1,0xff,2,0xdf,1,0xff,1,0xc0,1,0x02,1,0xbf,1,0xff,9,0xc0,1,0x00,1,0xff,2,0x9f,1,0xff,1,0xc0,1,0x00,1,0x0b,1,0xff,9,0xc0,1,0x00,1,0xff,4,0xc0,1,0x00,1,0x03,1,0xff,9,0xc0,1,0x00,1,0xff,2,0xdf,1,0xfb,1,0xe0,1,0x00,1,0x03,1,0xff,9,0xe0,1,0x00,1,0xab,1,0xfc,1,0xdf,1,0xf5,1,0xc0,1,0x00,1,0x03,1,0xff,9,0xc0,1,0x00,2,0x10,1,0x8f,1,0x83,1,0xc0,1,0x00,1,0x03,1,0xff,9,0xe0,1,0x00,2,0x01,1,0x8e,1,0x08,1,0xc0,1,0x00,1,0x07,1,0xff,8,0xfd,1,0xe0,1,0x00,1,0x04,1,0x39,1,0x85,1,0x05,1,0x80,1,0x00,1,0x07,1,0xff,8,0xfd,1,0xf0,1,0x00,1,0x4a,1,0xff,1,0x04,1,0x0a,1,0x80,1,0x00,1,0x0f,1,0xff,3,0xfe,1,0xff,4,0xfe,1,0xf0,1,0x00,1,0x01,1,0x7f,1,0x80,1,0x07,1,0x00,2,0x3f,1,0xff,3,0xfb,1,0xff,5,0x70,1,0x00,2,0x11,1,0x00,1,0x05,1,0x00,2,0x5f,1,0xff,1,0xaa,1,0xff,1,0xea,1,0xbf,1,0xff,4,0xa8,1,0x00,1,0xaa,1,0xff,1,0xa8,1,0x0a,1,0x85,1,0x00,1,0x3f,1,0xff,1,0xd5,1,0x7f,1,0xf5,1,0x5f,1,0xff,4,0xf0,1,0x00,1,0xab,1,0xf5,1,0x10,1,0x0a,1,0xbe,1,0x00,1,0x7f,1,0xff,1,0x55,1,0x57,1,0x68,1,0xbf,1,0xff,4,0xfc,1,0x00,1,0xa5,1,0x6a,1,0xa8,1,0x02,1,0xad,1,0x00,1,0xff,2,0xa2,1,0xaa,1,0xa8,1,0x1f,1,0xff,4,0xf8,1,0x00,1,0x95,1,0xa9,1,0x08,1,0x05,1,0xfe,1,0xa5,1,0xff,2,0x80,1,0x55,1,0x40,1,0x0f,1,0xff,4,0xf8,1,0x00,1,0x02,1,0xa0,1,0x34,1,0x47,1,0xff,1,0xab,1,0xff,2,0x40,1,0x05,1,0x00,1,0x1f,1,0xff,4,0xf8,1,0x00,1,0x88,1,0xa8,1,0x3d,1,0x07,1,0xfd,1,0x57,1,0xff,2,0x80,1,0x02,1,0x00,1,0x0f,1,0xff,4,0xf8,1,0x00,1,0x05,1,0x40,1,0x7e,1,0x9f,1,0xff,4,0x00,1,0x08,1,0x00,1,0x0f,1,0xff,4,0xf0,1,0x00,1,0x90,1,0x01,1,0x7f,1,0x2f,1,0xff,1,0x5f,1,0xff,2,0x80,1,0x00,2,0x07,1,0xff,4,0xf8,1,0x00,1,0x05,1,0x00,1,0xfe,1,0xbf,1,0xf7,1,0xff,3,0x00,3,0x0b,1,0xff,4,0xe0,1,0x00,2,0x01,1,0xfa,1,0x3f,1,0xfd,1,0x7f,1,0xff,1,0xfe,1,0x80,1,0x00,2,0x07,1,0xff,4,0xf0,1,0x00,2,0x03,1,0xfc,1,0xff,1,0x57,1,0xdf,1,0xff,2,0x00,3,0x03,1,0xff,4,0xd0,1,0x00,2,0x03,1,0xfa,1,0x7d,1,0xfa,1,0xb7,1,0xff,1,0xfe,1,0x00,3,0x05,1,0xff,4,0xe0,1,0x00,2,0x07,1,0xf4,1,0xf5,1,0x55,2,0xff,1,0xfe,1,0x00,3,0x01,1,0xff,4,0xd0,1,0x00,1,0x80,1,0x17,1,0xf5,1,0xd5,1,0x55,2,0x7f,1,0xfe,1,0x00,3,0x01,1,0xff,4,0xe0,1,0x00,2,0x05,1,0xaa,1,0xa8,1,0x40,1,0xaa,2,0xfc,1,0x00,4,0xff,4,0xe0,1,0x00,1,0xc0,1,0x05,1,0x50,1,0x81,1,0x2a,1,0x00,1,0x55,1,0x7c,1,0x00,3,0x01,1,0xff,4,0xe0,1,0x00,1,0xa0,1,0x0a,1,0x80,1,0x00,2,0x50,1,0x82,1,0xfc,1,0x00,4,0xff,4,0xc0,1,0x00,1,0xc0,1,0x04,1,0x00,4,0x01,1,0x78,1,0x00,4,0xff,4,0xc0,1,0x00,1,0x50,1,0x01,1,0x00,4,0x02,1,0xf8,1,0x00,4,0xff,4,0x80,1,0x00,7,0x01,1,0x78,1,0x00,4,0xff,4,0x40,1,0x00,8,0xa0,1,0x00,4,0xff,4,0xa0,1,0x00,1}
};

uint8_t* ExpandRLEArray(uint8_t idx, uint8_t *expandedArray) {
    uint8_t *rleArray = imgData[idx];
    uint8_t rleLength = sizeof(imgData[idx])/sizeof(imgData[0][0]);
    
    int index = 8;
    int expandedIndex = 0;

    while (index < rleLength) {
        int value = rleArray[index++];
        int count = rleArray[index++];

        for (int i = 0; i < count; i++) {
            expandedArray[expandedIndex++] = value;
        }
    }
}
LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_RICK_000 uint8_t rick_000_map[1240] = {0};
ExpandRLEArray(0, rick_000_map);
lv_img_dsc_t rick_000 = {
        .header.cf = LV_IMG_CF_INDEXED_1BIT,
        .header.always_zero = 0,
        .header.reserved = 0,
        .header.w = 140,
        .header.h = 68,
        .data_size = 1232,
        .data = rick_000_map,
        };

LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_RICK_001 uint8_t rick_001_map[1240] = {0};
ExpandRLEArray(1, rick_001_map);
lv_img_dsc_t rick_001 = {
        .header.cf = LV_IMG_CF_INDEXED_1BIT,
        .header.always_zero = 0,
        .header.reserved = 0,
        .header.w = 140,
        .header.h = 68,
        .data_size = 1232,
        .data = rick_001_map,
        };

