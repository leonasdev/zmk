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

struct Animation{
    const int frameCount;
    const int timeGap;
    const int repetition;
    const void *images[];
};

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
        &rocket_rush_000, &rocket_rush_001, &rocket_rush_002, &rocket_rush_003, &rocket_rush_004, &rocket_rush_005, &rocket_rush_006, &rocket_rush_007, &rocket_rush_008, &rocket_rush_009, &rocket_rush_010, &rocket_rush_011, &rocket_rush_012, &rocket_rush_013, &rocket_rush_014, &rocket_rush_015, &rocket_rush_016, &rocket_rush_017, &rocket_rush_018, &rocket_rush_019, &rocket_rush_020, &rocket_rush_021, &rocket_rush_022, &rocket_rush_023, &rocket_rush_024, &rocket_rush_025, &rocket_rush_026, &rocket_rush_027, &rocket_rush_028, &rocket_rush_029, &rocket_rush_030, &rocket_rush_031, &rocket_rush_032, &rocket_rush_033, &rocket_rush_034, &rocket_rush_035, &rocket_rush_036, &rocket_rush_037, &rocket_rush_038, &rocket_rush_039, &rocket_rush_040, &rocket_rush_041, &rocket_rush_042, &rocket_rush_043, &rocket_rush_044, &rocket_rush_045, &rocket_rush_046, &rocket_rush_047, &rocket_rush_048, &rocket_rush_049, &rocket_rush_050, &rocket_rush_051, &rocket_rush_052, &rocket_rush_053, &rocket_rush_054, &rocket_rush_055, &rocket_rush_056, &rocket_rush_057, &rocket_rush_058, &rocket_rush_059, &rocket_rush_060, &rocket_rush_061, &rocket_rush_062, &rocket_rush_063, &rocket_rush_064, &rocket_rush_065, &rocket_rush_066, &rocket_rush_067, &rocket_rush_068, &rocket_rush_069, &rocket_rush_070, &rocket_rush_071, &rocket_rush_072, &rocket_rush_073, &rocket_rush_074, &rocket_rush_075, &rocket_rush_076, &rocket_rush_077
    };

const struct Animation rocket_rush_anim = {
    .frameCount = 78,
    .timeGap = 40,
    .repetition = -1,
    .images = rocket_rush_images;
};


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
    lv_canvas_draw_rect(canvas, 0, 0, DISP_WIDTH, 20, &rect_black_dsc);

    // Draw battery
    draw_battery(canvas, state);

    // Draw output status
    lv_canvas_draw_text(canvas, 0, 0, CANVAS_SIZE, &label_dsc,
                        state.connected ? LV_SYMBOL_WIFI : LV_SYMBOL_CLOSE);

    // Rotate canvas
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

    draw_top(widget->obj, widget->cbuf, widget->state);
}

static void output_status_update_cb(struct peripheral_status_state state) {
    struct zmk_widget_status *widget;
    SYS_SLIST_FOR_EACH_CONTAINER(&widgets, widget, node) { set_connection_status(widget, state); }
}

ZMK_DISPLAY_WIDGET_LISTENER(widget_peripheral_status, struct peripheral_status_state,
                            output_status_update_cb, get_state)
ZMK_SUBSCRIPTION(widget_peripheral_status, zmk_split_peripheral_status_changed);

const void **images;
uint8_t images_len;

long long int idx = 0;
void set_img_src(void *var, int32_t val) {
    lv_obj_t *img = (lv_obj_t *)var;

    lv_img_set_src(img, rocket_rush_anim.images[val]);
}

int zmk_widget_status_init(struct zmk_widget_status *widget, lv_obj_t *parent) {
    widget->obj = lv_img_create(parent);
    
    lv_obj_set_size(widget->obj, 160, DISP_WIDTH);
    lv_obj_t *top = lv_canvas_create(widget->obj);
    lv_obj_align(top, LV_ALIGN_TOP_RIGHT, DISP_WIDTH, 0);
    lv_canvas_set_buffer(top, widget->cbuf, DISP_WIDTH, 20, LV_IMG_CF_TRUE_COLOR);

    // Params
    int anim_len = rocket_rush_anim.frameCount;
    int per_frame_time_in_ms = rocket_rush_anim.timeGap;

    // Init animations
    LOG_DBG("Setting animation!");

    lv_anim_init(&widget->anim);
    lv_anim_set_var(&widget->anim, widget->obj);
    lv_anim_set_time(&widget->anim, anim_len*per_frame_time_in_ms);
    lv_anim_set_values(&widget->anim, 0, anim_len-1);
    lv_anim_set_exec_cb(&widget->anim, (lv_anim_exec_xcb_t)set_img_src);
    lv_anim_set_repeat_count(&widget->anim, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_delay(&widget->anim, 1000);
    lv_anim_start(&widget->anim);

    sys_slist_append(&widgets, &widget->node);

    widget_battery_status_init();
    widget_peripheral_status_init();

    return 0;
}

lv_obj_t *zmk_widget_status_obj(struct zmk_widget_status *widget) { return widget->obj; }
