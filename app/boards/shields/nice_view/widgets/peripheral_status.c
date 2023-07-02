/*
 *
 * Copyright (c) 2023 The ZMK Contributors
 * SPDX-License-Identifier: MIT
 *
 */

#include <zephyr/kernel.h>
#include <zephyr/bluetooth/services/bas.h>
#include <zephyr/random/rand32.h>

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#include <zmk/display.h>
#include "peripheral_status.h"
#include <zmk/events/usb_conn_state_changed.h>
#include <zmk/event_manager.h>
#include <zmk/events/battery_state_changed.h>
#include <zmk/split/bluetooth/peripheral.h>
#include <zmk/events/split_peripheral_status_changed.h>
#include <zmk/usb.h>
#include <zmk/ble.h>

LV_IMG_DECLARE(cat_00)
LV_IMG_DECLARE(cat_01)
LV_IMG_DECLARE(cat_02)
LV_IMG_DECLARE(cat_03)
LV_IMG_DECLARE(cat_04)
LV_IMG_DECLARE(cat_05)
LV_IMG_DECLARE(cat_06)
LV_IMG_DECLARE(cat_07)
LV_IMG_DECLARE(cat_08)
LV_IMG_DECLARE(cat_09)
LV_IMG_DECLARE(cat_10)
LV_IMG_DECLARE(cat_11)
LV_IMG_DECLARE(cat_12)
LV_IMG_DECLARE(cat_13)
LV_IMG_DECLARE(cat_14)
LV_IMG_DECLARE(cat_15)
LV_IMG_DECLARE(cat_16)
LV_IMG_DECLARE(cat_17)
LV_IMG_DECLARE(cat_18)
LV_IMG_DECLARE(cat_19)
LV_IMG_DECLARE(cat_20)
LV_IMG_DECLARE(cat_21)
LV_IMG_DECLARE(cat_22)
LV_IMG_DECLARE(cat_23)

const void **images;
uint8_t images_len;

const void *cat_roll_images[] = {
    &cat_00, &cat_01, &cat_02, &cat_03, &cat_04, &cat_05, &cat_06, &cat_07, &cat_08, &cat_09, &cat_10, &cat_11, &cat_12, &cat_13, &cat_14, &cat_15, &cat_16, &cat_17, &cat_18, &cat_19, &cat_20, &cat_21, &cat_22, &cat_23
};


LV_IMG_DECLARE(jump_000)
LV_IMG_DECLARE(jump_001)
LV_IMG_DECLARE(jump_002)
LV_IMG_DECLARE(jump_003)
LV_IMG_DECLARE(jump_004)
LV_IMG_DECLARE(jump_005)
LV_IMG_DECLARE(jump_006)
LV_IMG_DECLARE(jump_007)
LV_IMG_DECLARE(jump_008)
LV_IMG_DECLARE(jump_009)
LV_IMG_DECLARE(jump_010)
LV_IMG_DECLARE(jump_011)
LV_IMG_DECLARE(jump_012)
LV_IMG_DECLARE(jump_013)
LV_IMG_DECLARE(jump_014)
LV_IMG_DECLARE(jump_015)
LV_IMG_DECLARE(jump_016)
LV_IMG_DECLARE(jump_017)
LV_IMG_DECLARE(jump_018)
LV_IMG_DECLARE(jump_019)
LV_IMG_DECLARE(jump_020)
LV_IMG_DECLARE(jump_021)
LV_IMG_DECLARE(jump_022)
LV_IMG_DECLARE(jump_023)
LV_IMG_DECLARE(jump_024)
LV_IMG_DECLARE(jump_025)
LV_IMG_DECLARE(jump_026)
LV_IMG_DECLARE(jump_027)
LV_IMG_DECLARE(jump_028)
LV_IMG_DECLARE(jump_029)
LV_IMG_DECLARE(jump_030)
LV_IMG_DECLARE(jump_031)
LV_IMG_DECLARE(jump_032)
LV_IMG_DECLARE(jump_033)
LV_IMG_DECLARE(jump_034)
LV_IMG_DECLARE(jump_035)
LV_IMG_DECLARE(jump_036)
LV_IMG_DECLARE(jump_037)
LV_IMG_DECLARE(jump_038)
LV_IMG_DECLARE(jump_039)
LV_IMG_DECLARE(jump_040)
LV_IMG_DECLARE(jump_041)
LV_IMG_DECLARE(jump_042)
LV_IMG_DECLARE(jump_043)
LV_IMG_DECLARE(jump_044)
LV_IMG_DECLARE(jump_045)
LV_IMG_DECLARE(jump_046)
LV_IMG_DECLARE(jump_047)
LV_IMG_DECLARE(jump_048)
LV_IMG_DECLARE(jump_049)
LV_IMG_DECLARE(jump_050)
LV_IMG_DECLARE(jump_051)
LV_IMG_DECLARE(jump_052)
LV_IMG_DECLARE(jump_053)
LV_IMG_DECLARE(jump_054)
LV_IMG_DECLARE(jump_055)
LV_IMG_DECLARE(jump_056)
LV_IMG_DECLARE(jump_057)
LV_IMG_DECLARE(jump_058)
LV_IMG_DECLARE(jump_059)
LV_IMG_DECLARE(jump_060)
LV_IMG_DECLARE(jump_061)
LV_IMG_DECLARE(jump_062)
LV_IMG_DECLARE(jump_063)
LV_IMG_DECLARE(jump_064)
LV_IMG_DECLARE(jump_065)
LV_IMG_DECLARE(jump_066)
LV_IMG_DECLARE(jump_067)
LV_IMG_DECLARE(jump_068)
LV_IMG_DECLARE(jump_069)
LV_IMG_DECLARE(jump_070)
LV_IMG_DECLARE(jump_071)
LV_IMG_DECLARE(jump_072)
LV_IMG_DECLARE(jump_073)
LV_IMG_DECLARE(jump_074)
LV_IMG_DECLARE(jump_075)
LV_IMG_DECLARE(jump_076)
LV_IMG_DECLARE(jump_077)
LV_IMG_DECLARE(jump_078)
LV_IMG_DECLARE(jump_079)
LV_IMG_DECLARE(jump_080)
LV_IMG_DECLARE(jump_081)
LV_IMG_DECLARE(jump_082)
LV_IMG_DECLARE(jump_083)
LV_IMG_DECLARE(jump_084)
LV_IMG_DECLARE(jump_085)
LV_IMG_DECLARE(jump_086)
LV_IMG_DECLARE(jump_087)
LV_IMG_DECLARE(jump_088)
LV_IMG_DECLARE(jump_089)
LV_IMG_DECLARE(jump_090)
LV_IMG_DECLARE(jump_091)
LV_IMG_DECLARE(jump_092)
LV_IMG_DECLARE(jump_093)
LV_IMG_DECLARE(jump_094)
LV_IMG_DECLARE(jump_095)
LV_IMG_DECLARE(jump_096)
LV_IMG_DECLARE(jump_097)
LV_IMG_DECLARE(jump_098)
LV_IMG_DECLARE(jump_099)
LV_IMG_DECLARE(jump_100)
LV_IMG_DECLARE(jump_101)
LV_IMG_DECLARE(jump_102)
LV_IMG_DECLARE(jump_103)
LV_IMG_DECLARE(jump_104)
LV_IMG_DECLARE(jump_105)
LV_IMG_DECLARE(jump_106)
LV_IMG_DECLARE(jump_107)
LV_IMG_DECLARE(jump_108)
LV_IMG_DECLARE(jump_109)
LV_IMG_DECLARE(jump_110)
LV_IMG_DECLARE(jump_111)
LV_IMG_DECLARE(jump_112)
LV_IMG_DECLARE(jump_113)
LV_IMG_DECLARE(jump_114)
LV_IMG_DECLARE(jump_115)
LV_IMG_DECLARE(jump_116)
LV_IMG_DECLARE(jump_117)
LV_IMG_DECLARE(jump_118)
LV_IMG_DECLARE(jump_119)
LV_IMG_DECLARE(jump_120)
LV_IMG_DECLARE(jump_121)
LV_IMG_DECLARE(jump_122)
LV_IMG_DECLARE(jump_123)
LV_IMG_DECLARE(jump_124)
LV_IMG_DECLARE(jump_125)
LV_IMG_DECLARE(jump_126)
LV_IMG_DECLARE(jump_127)
LV_IMG_DECLARE(jump_128)
LV_IMG_DECLARE(jump_129)
LV_IMG_DECLARE(jump_130)
LV_IMG_DECLARE(jump_131)
LV_IMG_DECLARE(jump_132)
LV_IMG_DECLARE(jump_133)
LV_IMG_DECLARE(jump_134)
LV_IMG_DECLARE(jump_135)
LV_IMG_DECLARE(jump_136)
LV_IMG_DECLARE(jump_137)
LV_IMG_DECLARE(jump_138)
LV_IMG_DECLARE(jump_139)
LV_IMG_DECLARE(jump_140)
LV_IMG_DECLARE(jump_141)
LV_IMG_DECLARE(jump_142)
LV_IMG_DECLARE(jump_143)
LV_IMG_DECLARE(jump_144)
LV_IMG_DECLARE(jump_145)
LV_IMG_DECLARE(jump_146)
LV_IMG_DECLARE(jump_147)
LV_IMG_DECLARE(jump_148)
LV_IMG_DECLARE(jump_149)
LV_IMG_DECLARE(jump_150)
LV_IMG_DECLARE(jump_151)
LV_IMG_DECLARE(jump_152)
LV_IMG_DECLARE(jump_153)
LV_IMG_DECLARE(jump_154)
LV_IMG_DECLARE(jump_155)
LV_IMG_DECLARE(jump_156)
LV_IMG_DECLARE(jump_157)
LV_IMG_DECLARE(jump_158)
LV_IMG_DECLARE(jump_159)
LV_IMG_DECLARE(jump_160)
LV_IMG_DECLARE(jump_161)
LV_IMG_DECLARE(jump_162)
LV_IMG_DECLARE(jump_163)
LV_IMG_DECLARE(jump_164)
LV_IMG_DECLARE(jump_165)
LV_IMG_DECLARE(jump_166)
LV_IMG_DECLARE(jump_167)
const void *jump_images[] = {
&jump_000, &jump_001, &jump_002, &jump_003, &jump_004, &jump_005, &jump_006, &jump_007, &jump_008, &jump_009, &jump_010, &jump_011, &jump_012, &jump_013, &jump_014, &jump_015, &jump_016, &jump_017, &jump_018, &jump_019, &jump_020, &jump_021, &jump_022, &jump_023, &jump_024, &jump_025, &jump_026, &jump_027, &jump_028, &jump_029, &jump_030, &jump_031, &jump_032, &jump_033, &jump_034, &jump_035, &jump_036, &jump_037, &jump_038, &jump_039, &jump_040, &jump_041, &jump_042, &jump_043, &jump_044, &jump_045, &jump_046, &jump_047, &jump_048, &jump_049, &jump_050, &jump_051, &jump_052, &jump_053, &jump_054, &jump_055, &jump_056, &jump_057, &jump_058, &jump_059, &jump_060, &jump_061, &jump_062, &jump_063, &jump_064, &jump_065, &jump_066, &jump_067, &jump_068, &jump_069, &jump_070, &jump_071, &jump_072, &jump_073, &jump_074, &jump_075, &jump_076, &jump_077, &jump_078, &jump_079, &jump_080, &jump_081, &jump_082, &jump_083, &jump_084, &jump_085, &jump_086, &jump_087, &jump_088, &jump_089, &jump_090, &jump_091, &jump_092, &jump_093, &jump_094, &jump_095, &jump_096, &jump_097, &jump_098, &jump_099, &jump_100, &jump_101, &jump_102, &jump_103, &jump_104, &jump_105, &jump_106, &jump_107, &jump_108, &jump_109, &jump_110, &jump_111, &jump_112, &jump_113, &jump_114, &jump_115, &jump_116, &jump_117, &jump_118, &jump_119, &jump_120, &jump_121, &jump_122, &jump_123, &jump_124, &jump_125, &jump_126, &jump_127, &jump_128, &jump_129, &jump_130, &jump_131, &jump_132, &jump_133, &jump_134, &jump_135, &jump_136, &jump_137, &jump_138, &jump_139, &jump_140, &jump_141, &jump_142, &jump_143, &jump_144, &jump_145, &jump_146, &jump_147, &jump_148, &jump_149, &jump_150, &jump_151, &jump_152, &jump_153, &jump_154, &jump_155, &jump_156, &jump_157, &jump_158, &jump_159, &jump_160, &jump_161, &jump_162, &jump_163, &jump_164, &jump_165, &jump_166, &jump_167
};

LV_IMG_DECLARE(rocket_jump_000)
LV_IMG_DECLARE(rocket_jump_001)
LV_IMG_DECLARE(rocket_jump_002)
LV_IMG_DECLARE(rocket_jump_003)
LV_IMG_DECLARE(rocket_jump_004)
LV_IMG_DECLARE(rocket_jump_005)
LV_IMG_DECLARE(rocket_jump_006)
LV_IMG_DECLARE(rocket_jump_007)
LV_IMG_DECLARE(rocket_jump_008)
LV_IMG_DECLARE(rocket_jump_009)
LV_IMG_DECLARE(rocket_jump_010)
LV_IMG_DECLARE(rocket_jump_011)
LV_IMG_DECLARE(rocket_jump_012)
LV_IMG_DECLARE(rocket_jump_013)
LV_IMG_DECLARE(rocket_jump_014)
LV_IMG_DECLARE(rocket_jump_015)
LV_IMG_DECLARE(rocket_jump_016)
LV_IMG_DECLARE(rocket_jump_017)
LV_IMG_DECLARE(rocket_jump_018)
LV_IMG_DECLARE(rocket_jump_019)
LV_IMG_DECLARE(rocket_jump_020)
LV_IMG_DECLARE(rocket_jump_021)
LV_IMG_DECLARE(rocket_jump_022)
LV_IMG_DECLARE(rocket_jump_023)
LV_IMG_DECLARE(rocket_jump_024)
LV_IMG_DECLARE(rocket_jump_025)
LV_IMG_DECLARE(rocket_jump_026)
LV_IMG_DECLARE(rocket_jump_027)
LV_IMG_DECLARE(rocket_jump_028)
LV_IMG_DECLARE(rocket_jump_029)
LV_IMG_DECLARE(rocket_jump_030)
LV_IMG_DECLARE(rocket_jump_031)
LV_IMG_DECLARE(rocket_jump_032)
LV_IMG_DECLARE(rocket_jump_033)
LV_IMG_DECLARE(rocket_jump_034)
LV_IMG_DECLARE(rocket_jump_035)
LV_IMG_DECLARE(rocket_jump_036)
LV_IMG_DECLARE(rocket_jump_037)
LV_IMG_DECLARE(rocket_jump_038)
LV_IMG_DECLARE(rocket_jump_039)
LV_IMG_DECLARE(rocket_jump_040)
LV_IMG_DECLARE(rocket_jump_041)
LV_IMG_DECLARE(rocket_jump_042)
LV_IMG_DECLARE(rocket_jump_043)
LV_IMG_DECLARE(rocket_jump_044)
LV_IMG_DECLARE(rocket_jump_045)
LV_IMG_DECLARE(rocket_jump_046)
LV_IMG_DECLARE(rocket_jump_047)
LV_IMG_DECLARE(rocket_jump_048)
LV_IMG_DECLARE(rocket_jump_049)
const void *rocket_jump_images[] = {
&rocket_jump_000, &rocket_jump_001, &rocket_jump_002, &rocket_jump_003, &rocket_jump_004, &rocket_jump_005, &rocket_jump_006, &rocket_jump_007, &rocket_jump_008, &rocket_jump_009, &rocket_jump_010, &rocket_jump_011, &rocket_jump_012, &rocket_jump_013, &rocket_jump_014, &rocket_jump_015, &rocket_jump_016, &rocket_jump_017, &rocket_jump_018, &rocket_jump_019, &rocket_jump_020, &rocket_jump_021, &rocket_jump_022, &rocket_jump_023, &rocket_jump_024, &rocket_jump_025, &rocket_jump_026, &rocket_jump_027, &rocket_jump_028, &rocket_jump_029, &rocket_jump_030, &rocket_jump_031, &rocket_jump_032, &rocket_jump_033, &rocket_jump_034, &rocket_jump_035, &rocket_jump_036, &rocket_jump_037, &rocket_jump_038, &rocket_jump_039, &rocket_jump_040, &rocket_jump_041, &rocket_jump_042, &rocket_jump_043, &rocket_jump_044, &rocket_jump_045, &rocket_jump_046, &rocket_jump_047, &rocket_jump_048, &rocket_jump_049};

LV_IMG_DECLARE(dance_000)
LV_IMG_DECLARE(dance_001)
LV_IMG_DECLARE(dance_002)
LV_IMG_DECLARE(dance_003)
LV_IMG_DECLARE(dance_004)
LV_IMG_DECLARE(dance_005)
LV_IMG_DECLARE(dance_006)
LV_IMG_DECLARE(dance_007)
LV_IMG_DECLARE(dance_008)
LV_IMG_DECLARE(dance_009)
LV_IMG_DECLARE(dance_010)
LV_IMG_DECLARE(dance_011)
LV_IMG_DECLARE(dance_012)
LV_IMG_DECLARE(dance_013)
LV_IMG_DECLARE(dance_014)
LV_IMG_DECLARE(dance_015)
LV_IMG_DECLARE(dance_016)
LV_IMG_DECLARE(dance_017)
LV_IMG_DECLARE(dance_018)
LV_IMG_DECLARE(dance_019)
LV_IMG_DECLARE(dance_020)
LV_IMG_DECLARE(dance_021)
LV_IMG_DECLARE(dance_022)
LV_IMG_DECLARE(dance_023)
LV_IMG_DECLARE(dance_024)
LV_IMG_DECLARE(dance_025)
LV_IMG_DECLARE(dance_026)
LV_IMG_DECLARE(dance_027)
LV_IMG_DECLARE(dance_028)
LV_IMG_DECLARE(dance_029)
LV_IMG_DECLARE(dance_030)
LV_IMG_DECLARE(dance_031)
LV_IMG_DECLARE(dance_032)
LV_IMG_DECLARE(dance_033)
LV_IMG_DECLARE(dance_034)
LV_IMG_DECLARE(dance_035)
LV_IMG_DECLARE(dance_036)
LV_IMG_DECLARE(dance_037)
LV_IMG_DECLARE(dance_038)
LV_IMG_DECLARE(dance_039)
LV_IMG_DECLARE(dance_040)
LV_IMG_DECLARE(dance_041)
LV_IMG_DECLARE(dance_042)
LV_IMG_DECLARE(dance_043)
LV_IMG_DECLARE(dance_044)
LV_IMG_DECLARE(dance_045)
const void *dance_images[] = {
&dance_000, &dance_001, &dance_002, &dance_003, &dance_004, &dance_005, &dance_006, &dance_007, &dance_008, &dance_009, &dance_010, &dance_011, &dance_012, &dance_013, &dance_014, &dance_015, &dance_016, &dance_017, &dance_018, &dance_019, &dance_020, &dance_021, &dance_022, &dance_023, &dance_024, &dance_025, &dance_026, &dance_027, &dance_028, &dance_029, &dance_030, &dance_031, &dance_032, &dance_033, &dance_034, &dance_035, &dance_036, &dance_037, &dance_038, &dance_039, &dance_040, &dance_041, &dance_042, &dance_043, &dance_044, &dance_045};

LV_IMG_DECLARE(rocket_rush_000)
LV_IMG_DECLARE(rocket_rush_001)
LV_IMG_DECLARE(rocket_rush_002)
LV_IMG_DECLARE(rocket_rush_003)
LV_IMG_DECLARE(rocket_rush_004)
LV_IMG_DECLARE(rocket_rush_005)
LV_IMG_DECLARE(rocket_rush_006)
LV_IMG_DECLARE(rocket_rush_007)
LV_IMG_DECLARE(rocket_rush_008)
LV_IMG_DECLARE(rocket_rush_009)
LV_IMG_DECLARE(rocket_rush_010)
LV_IMG_DECLARE(rocket_rush_011)
LV_IMG_DECLARE(rocket_rush_012)
LV_IMG_DECLARE(rocket_rush_013)
LV_IMG_DECLARE(rocket_rush_014)
LV_IMG_DECLARE(rocket_rush_015)
LV_IMG_DECLARE(rocket_rush_016)
LV_IMG_DECLARE(rocket_rush_017)
LV_IMG_DECLARE(rocket_rush_018)
LV_IMG_DECLARE(rocket_rush_019)
LV_IMG_DECLARE(rocket_rush_020)
LV_IMG_DECLARE(rocket_rush_021)
LV_IMG_DECLARE(rocket_rush_022)
LV_IMG_DECLARE(rocket_rush_023)
LV_IMG_DECLARE(rocket_rush_024)
LV_IMG_DECLARE(rocket_rush_025)
LV_IMG_DECLARE(rocket_rush_026)
LV_IMG_DECLARE(rocket_rush_027)
LV_IMG_DECLARE(rocket_rush_028)
LV_IMG_DECLARE(rocket_rush_029)
LV_IMG_DECLARE(rocket_rush_030)
LV_IMG_DECLARE(rocket_rush_031)
LV_IMG_DECLARE(rocket_rush_032)
LV_IMG_DECLARE(rocket_rush_033)
LV_IMG_DECLARE(rocket_rush_034)
LV_IMG_DECLARE(rocket_rush_035)
LV_IMG_DECLARE(rocket_rush_036)
LV_IMG_DECLARE(rocket_rush_037)
LV_IMG_DECLARE(rocket_rush_038)
LV_IMG_DECLARE(rocket_rush_039)
LV_IMG_DECLARE(rocket_rush_040)
LV_IMG_DECLARE(rocket_rush_041)
LV_IMG_DECLARE(rocket_rush_042)
LV_IMG_DECLARE(rocket_rush_043)
LV_IMG_DECLARE(rocket_rush_044)
LV_IMG_DECLARE(rocket_rush_045)
LV_IMG_DECLARE(rocket_rush_046)
LV_IMG_DECLARE(rocket_rush_047)
LV_IMG_DECLARE(rocket_rush_048)
LV_IMG_DECLARE(rocket_rush_049)
LV_IMG_DECLARE(rocket_rush_050)
LV_IMG_DECLARE(rocket_rush_051)
LV_IMG_DECLARE(rocket_rush_052)
LV_IMG_DECLARE(rocket_rush_053)
LV_IMG_DECLARE(rocket_rush_054)
LV_IMG_DECLARE(rocket_rush_055)
LV_IMG_DECLARE(rocket_rush_056)
LV_IMG_DECLARE(rocket_rush_057)
LV_IMG_DECLARE(rocket_rush_058)
LV_IMG_DECLARE(rocket_rush_059)
LV_IMG_DECLARE(rocket_rush_060)
LV_IMG_DECLARE(rocket_rush_061)
LV_IMG_DECLARE(rocket_rush_062)
LV_IMG_DECLARE(rocket_rush_063)
LV_IMG_DECLARE(rocket_rush_064)
LV_IMG_DECLARE(rocket_rush_065)
LV_IMG_DECLARE(rocket_rush_066)
LV_IMG_DECLARE(rocket_rush_067)
LV_IMG_DECLARE(rocket_rush_068)
LV_IMG_DECLARE(rocket_rush_069)
LV_IMG_DECLARE(rocket_rush_070)
LV_IMG_DECLARE(rocket_rush_071)
LV_IMG_DECLARE(rocket_rush_072)
LV_IMG_DECLARE(rocket_rush_073)
LV_IMG_DECLARE(rocket_rush_074)
LV_IMG_DECLARE(rocket_rush_075)
LV_IMG_DECLARE(rocket_rush_076)
LV_IMG_DECLARE(rocket_rush_077)
const void *rocket_rush_images[] = {
&rocket_rush_000, &rocket_rush_001, &rocket_rush_002, &rocket_rush_003, &rocket_rush_004, &rocket_rush_005, &rocket_rush_006, &rocket_rush_007, &rocket_rush_008, &rocket_rush_009, &rocket_rush_010, &rocket_rush_011, &rocket_rush_012, &rocket_rush_013, &rocket_rush_014, &rocket_rush_015, &rocket_rush_016, &rocket_rush_017, &rocket_rush_018, &rocket_rush_019, &rocket_rush_020, &rocket_rush_021, &rocket_rush_022, &rocket_rush_023, &rocket_rush_024, &rocket_rush_025, &rocket_rush_026, &rocket_rush_027, &rocket_rush_028, &rocket_rush_029, &rocket_rush_030, &rocket_rush_031, &rocket_rush_032, &rocket_rush_033, &rocket_rush_034, &rocket_rush_035, &rocket_rush_036, &rocket_rush_037, &rocket_rush_038, &rocket_rush_039, &rocket_rush_040, &rocket_rush_041, &rocket_rush_042, &rocket_rush_043, &rocket_rush_044, &rocket_rush_045, &rocket_rush_046, &rocket_rush_047, &rocket_rush_048, &rocket_rush_049, &rocket_rush_050, &rocket_rush_051, &rocket_rush_052, &rocket_rush_053, &rocket_rush_054, &rocket_rush_055, &rocket_rush_056, &rocket_rush_057, &rocket_rush_058, &rocket_rush_059, &rocket_rush_060, &rocket_rush_061, &rocket_rush_062, &rocket_rush_063, &rocket_rush_064, &rocket_rush_065, &rocket_rush_066, &rocket_rush_067, &rocket_rush_068, &rocket_rush_069, &rocket_rush_070, &rocket_rush_071, &rocket_rush_072, &rocket_rush_073, &rocket_rush_074, &rocket_rush_075, &rocket_rush_076, &rocket_rush_077};


static sys_slist_t widgets = SYS_SLIST_STATIC_INIT(&widgets);

struct peripheral_status_state {
    bool connected;
};

static void draw_top(lv_obj_t *widget, lv_color_t cbuf[], struct status_state state) {
    lv_obj_t *canvas = lv_obj_get_child(widget, 0);

    lv_draw_label_dsc_t label_dsc;
    init_label_dsc(&label_dsc, LVGL_FOREGROUND, &lv_font_montserrat_16, LV_TEXT_ALIGN_RIGHT);
    lv_draw_rect_dsc_t rect_black_dsc;
    init_rect_dsc(&rect_black_dsc, LVGL_BACKGROUND);

    // Fill background
    lv_canvas_draw_rect(canvas, 0, 0, 168, 20, &rect_black_dsc);

    // Draw battery
    draw_battery(canvas, state);

    // Draw output status
    lv_canvas_draw_text(canvas, 0, 0, CANVAS_SIZE, &label_dsc,
                        state.connected ? LV_SYMBOL_WIFI : LV_SYMBOL_CLOSE);

    // // Rotate canvas
    rotate_canvas(canvas, cbuf);
}

static void set_battery_status(struct zmk_widget_status *widget,
                               struct battery_status_state state) {
#if IS_ENABLED(CONFIG_USB_DEVICE_STACK)
    widget->state.charging = state.usb_present;
#endif /* IS_ENABLED(CONFIG_USB_DEVICE_STACK) */

    widget->state.battery = state.level;

    draw_top(widget->obj, widget->cbuf, widget->state);
}

static void battery_status_update_cb(struct battery_status_state state) {
    struct zmk_widget_status *widget;
    SYS_SLIST_FOR_EACH_CONTAINER(&widgets, widget, node) { set_battery_status(widget, state); }
}

static struct battery_status_state battery_status_get_state(const zmk_event_t *eh) {
    return (struct battery_status_state) {
        .level = bt_bas_get_battery_level(),
#if IS_ENABLED(CONFIG_USB_DEVICE_STACK)
        .usb_present = zmk_usb_is_powered(),
#endif /* IS_ENABLED(CONFIG_USB_DEVICE_STACK) */
    };
}

ZMK_DISPLAY_WIDGET_LISTENER(widget_battery_status, struct battery_status_state,
                            battery_status_update_cb, battery_status_get_state)

ZMK_SUBSCRIPTION(widget_battery_status, zmk_battery_state_changed);
#if IS_ENABLED(CONFIG_USB_DEVICE_STACK)
ZMK_SUBSCRIPTION(widget_battery_status, zmk_usb_conn_state_changed);
#endif /* IS_ENABLED(CONFIG_USB_DEVICE_STACK) */

static struct peripheral_status_state get_state(const zmk_event_t *_eh) {
    return (struct peripheral_status_state){.connected = zmk_split_bt_peripheral_is_connected()};
}

static void set_connection_status(struct zmk_widget_status *widget,
                                  struct peripheral_status_state state) {
    widget->state.connected = state.connected;

    // draw_top(widget->obj, widget->cbuf, widget->state);
}

static void output_status_update_cb(struct peripheral_status_state state) {
    struct zmk_widget_status *widget;
    SYS_SLIST_FOR_EACH_CONTAINER(&widgets, widget, node) { set_connection_status(widget, state); }
}

ZMK_DISPLAY_WIDGET_LISTENER(widget_peripheral_status, struct peripheral_status_state,
                            output_status_update_cb, get_state)
ZMK_SUBSCRIPTION(widget_peripheral_status, zmk_split_peripheral_status_changed);

struct zmk_widget_status *widgetRef;
void set_img_src(void *var, int32_t val) {
    lv_obj_t *img = (lv_obj_t *)var;
    lv_img_set_src(img, images[val]);
    lv_obj_align(img, LV_ALIGN_TOP_LEFT, 0, 0);

    // draw_top(widgetRef->obj, widgetRef->cbuf, widgetRef->state);
}

int zmk_widget_status_init(struct zmk_widget_status *widget, lv_obj_t *parent) {
    widget->obj = lv_img_create(parent);
    
    lv_obj_set_size(widget->obj, 160, 68);
    lv_obj_t *top = lv_canvas_create(widget->obj);
    lv_obj_align(top, LV_ALIGN_TOP_RIGHT, 0, 0);
    lv_canvas_set_buffer(top, widget->cbuf, 168, 20, LV_IMG_CF_TRUE_COLOR);

    // Params
    int anim_len = 78;
    int per_frame_time_in_ms = 2000;
    images = rocket_rush_images;

    // Init animations
    LOG_DBG("Setting animation!");
    lv_anim_init(&widget->anim);
    lv_anim_set_var(&widget->anim, widget->obj);
    lv_anim_set_time(&widget->anim, anim_len*per_frame_time_in_ms);
    lv_anim_set_values(&widget->anim, 0, anim_len-1);
    lv_anim_set_exec_cb(&widget->anim, (lv_anim_exec_xcb_t)set_img_src);
    lv_anim_set_repeat_count(&widget->anim, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_delay(&widget->anim, 10000);
    lv_anim_start(&widget->anim);

    sys_slist_append(&widgets, &widget->node);

    widget_battery_status_init();
    widget_peripheral_status_init();

    widgetRef=widget;

    return 0;
}

lv_obj_t *zmk_widget_status_obj(struct zmk_widget_status *widget) { return widget->obj; }
