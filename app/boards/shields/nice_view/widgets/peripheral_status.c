/*
 *
 * Copyright (c) 2023 The ZMK Contributors
 * SPDX-License-Identifier: MIT
 *
 */

#include <zephyr/kernel.h>
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


static sys_slist_t widgets = SYS_SLIST_STATIC_INIT(&widgets);

void set_img_src(void *var, int32_t val) {
    lv_obj_t *img = (lv_obj_t *)var;
    lv_img_set_src(img, images[val]);
}

int zmk_widget_status_init(struct zmk_widget_status *widget, lv_obj_t *parent) {
    widget->obj = lv_img_create(parent);
    // lv_obj_set_size(widget->obj, 160, 68);

    LOG_DBG("Set source to cat roll images!");
    // lv_anim_init(&widget->anim);
    // lv_anim_set_var(&widget->anim, widget->obj);
    // lv_anim_set_time(&widget->anim, 1000);
    // lv_anim_set_values(&widget->anim, 0, 10);
    // lv_anim_set_exec_cb(&widget->anim, (lv_anim_exec_xcb_t)set_img_src);
    // lv_anim_set_repeat_count(&widget->anim, LV_ANIM_REPEAT_INFINITE);
    // lv_anim_set_repeat_delay(&widget->anim, 100);
    // images = cat_roll_images;
    // lv_anim_start(&widget->anim);

    sys_slist_append(&widgets, &widget->node);

    return 0;
}

lv_obj_t *zmk_widget_status_obj(struct zmk_widget_status *widget) { return widget->obj; }
