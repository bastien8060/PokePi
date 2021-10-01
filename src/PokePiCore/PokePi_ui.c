#include "PokePi_ui.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * Loader;
lv_obj_t * Image1;
lv_obj_t * Loading_Text;
lv_obj_t * Home;
lv_obj_t * Image5;
lv_obj_t * Object2;

///////////////////// IMAGES ////////////////////
LV_IMG_DECLARE(img_boot_png);   // assets\boot.png
LV_IMG_DECLARE(img_small_png);   // assets\small.png

///////////////////// FUNCTIONS ////////////////////
#define BAR_PROPERTY_VALUE 0
#define BAR_PROPERTY_VALUE_WITH_ANIM 1

void SetBarProperty(lv_obj_t * target, int id, int val)
{
    if(id == BAR_PROPERTY_VALUE_WITH_ANIM) lv_bar_set_value(target, val, LV_ANIM_ON);
    if(id == BAR_PROPERTY_VALUE) lv_bar_set_value(target, val, LV_ANIM_OFF);
}

#define BASIC_PROPERTY_POSITION_X 0
#define BASIC_PROPERTY_POSITION_Y 1
#define BASIC_PROPERTY_WIDTH 2
#define BASIC_PROPERTY_HEIGHT 3
#define BASIC_PROPERTY_CLICKABLE 4
#define BASIC_PROPERTY_HIDDEN 5
#define BASIC_PROPERTY_DRAGABLE 6
#define BASIC_PROPERTY_DISABLED 7

void SetBasicProperty(lv_obj_t * target, int id, int val)
{
    if(id == BASIC_PROPERTY_POSITION_X) lv_obj_set_x(target, val);
    if(id == BASIC_PROPERTY_POSITION_Y) lv_obj_set_y(target, val);
    if(id == BASIC_PROPERTY_WIDTH) lv_obj_set_width(target, val);
    if(id == BASIC_PROPERTY_HEIGHT) lv_obj_set_height(target, val);
}

void SetBasicPropertyB(lv_obj_t * target, int id, bool val)
{
    if(id == BASIC_PROPERTY_CLICKABLE) lv_obj_set_click(target, val);
    if(id == BASIC_PROPERTY_HIDDEN) lv_obj_set_hidden(target, val);
    if(id == BASIC_PROPERTY_DRAGABLE) lv_obj_set_drag(target, val);
    if(id == BASIC_PROPERTY_DISABLED) {
        if(val) lv_obj_add_state(target, LV_STATE_DISABLED);
        else lv_obj_clear_state(target, LV_STATE_DISABLED);
    }
}

#define BUTTON_PROPERTY_TOGGLE 0
#define BUTTON_PROPERTY_CHECKED 1

void SetButtonProperty(lv_obj_t * target, int id, bool val)
{
    if(id == BUTTON_PROPERTY_TOGGLE) lv_btn_toggle(target);
    if(id == BUTTON_PROPERTY_CHECKED) lv_btn_set_state(target, val ? LV_BTN_STATE_CHECKED_RELEASED : LV_BTN_STATE_RELEASED);
}

#define DROPDOWN_PROPERTY_SELECTED 0

void SetDropdownProperty(lv_obj_t * target, int id, int val)
{
    if(id == DROPDOWN_PROPERTY_SELECTED) lv_dropdown_set_selected(target, val);
}

#define IMAGE_PROPERTY_IMAGE 0

void SetImageProperty(lv_obj_t * target, int id, uint8_t * val)
{
    if(id == IMAGE_PROPERTY_IMAGE) lv_img_set_src(target, val);
}

#define LABEL_PROPERTY_TEXT 0

void SetLabelProperty(lv_obj_t * target, int id, char * val)
{
    if(id == LABEL_PROPERTY_TEXT) lv_label_set_text(target, val);
}

#define ROLLER_PROPERTY_SELECTED 0
#define ROLLER_PROPERTY_SELECTED_WITH_ANIM 1

void SetRollerProperty(lv_obj_t * target, int id, int val)
{
    if(id == ROLLER_PROPERTY_SELECTED_WITH_ANIM) lv_roller_set_selected(target, val, LV_ANIM_ON);
    if(id == ROLLER_PROPERTY_SELECTED) lv_roller_set_selected(target, val, LV_ANIM_OFF);
}

#define SLIDER_PROPERTY_VALUE 0
#define SLIDER_PROPERTY_VALUE_WITH_ANIM 1

void SetSliderProperty(lv_obj_t * target, int id, int val)
{
    if(id == SLIDER_PROPERTY_VALUE_WITH_ANIM) lv_slider_set_value(target, val, LV_ANIM_ON);
    if(id == SLIDER_PROPERTY_VALUE) lv_slider_set_value(target, val, LV_ANIM_OFF);
}

void ChangeScreen(lv_obj_t * target, int fademode, int spd, int delay)
{
    lv_scr_load_anim(target, fademode, spd, delay, false);
}

void SetOpacity(lv_obj_t * target, int val)
{
    lv_obj_set_style_local_opa_scale(target, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, val);
}

void anim_callback_set_x(lv_anim_t * a, lv_anim_value_t v)
{
    lv_obj_set_x(a->user_data, v);
}

void anim_callback_set_y(lv_anim_t * a, lv_anim_value_t v)
{
    lv_obj_set_y(a->user_data, v);
}

void anim_callback_set_width(lv_anim_t * a, lv_anim_value_t v)
{
    lv_obj_set_width(a->user_data, v);
}

void anim_callback_set_height(lv_anim_t * a, lv_anim_value_t v)
{
    lv_obj_set_height(a->user_data, v);
}

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS2 ////////////////////
static void Object2_eventhandler(lv_obj_t * obj, lv_event_t event)
{
}

///////////////////// SCREENS ////////////////////
void BuildPages(void)
{
    Loader = lv_obj_create(NULL, NULL);

    Image1 = lv_img_create(Loader, NULL);
    lv_img_set_src(Image1, &img_boot_png);
    lv_obj_set_click(Image1, false);
    lv_obj_set_hidden(Image1, false);
    lv_obj_set_size(Image1, 130, 130);
    lv_obj_align(Image1, Loader, LV_ALIGN_CENTER, 0, -33);
    lv_obj_set_drag(Image1, false);

    lv_obj_clear_state(Image1, LV_STATE_DISABLED);

    Loading_Text = lv_label_create(Loader, NULL);
    lv_label_set_long_mode(Loading_Text, LV_LABEL_LONG_EXPAND);
    lv_label_set_align(Loading_Text, LV_LABEL_ALIGN_CENTER);
    lv_label_set_text(Loading_Text, " Loading ");
    lv_obj_set_size(Loading_Text, 227, 16);  // force: 2
    lv_obj_set_click(Loading_Text, false);
    lv_obj_set_hidden(Loading_Text, false);
    lv_obj_clear_state(Loading_Text, LV_STATE_DISABLED);
    lv_obj_set_drag(Loading_Text, false);
    lv_obj_set_style_local_text_color(Loading_Text, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,
                                      lv_color_hex(128 * 256 * 256 + 128 * 256 + 128));
    lv_obj_set_style_local_text_opa(Loading_Text, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 255);
    lv_obj_set_style_local_text_letter_space(Loading_Text, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 20);
    lv_obj_set_style_local_text_line_space(Loading_Text, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);
    lv_obj_set_style_local_shadow_width(Loading_Text, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 150);
    lv_obj_set_style_local_shadow_spread(Loading_Text, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 1);

    lv_obj_align(Loading_Text, Loader, LV_ALIGN_CENTER, 2, 94); // force: 227

    Home = lv_obj_create(NULL, NULL);

    Image5 = lv_img_create(Home, NULL);
    lv_img_set_src(Image5, &img_small_png);
    lv_obj_set_click(Image5, false);
    lv_obj_set_hidden(Image5, false);
    lv_obj_set_size(Image5, 569, 320);
    lv_obj_align(Image5, Home, LV_ALIGN_CENTER, -44, 0);
    lv_obj_set_drag(Image5, false);

    lv_obj_clear_state(Image5, LV_STATE_DISABLED);

    Object2 = lv_obj_create(Home, NULL);
    lv_obj_set_click(Object2, true);
    lv_obj_set_hidden(Object2, false);
    lv_obj_clear_state(Object2, LV_STATE_DISABLED);
    lv_obj_set_size(Object2, 453, 289);  // force: -1
    lv_obj_align(Object2, Home, LV_ALIGN_CENTER, -1, -2); // force: 453
    lv_obj_set_drag(Object2, false);
    lv_obj_set_event_cb(Object2, Object2_eventhandler);
    lv_obj_set_style_local_bg_color(Object2, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,
                                    lv_color_hex(255 * 256 * 256 + 255 * 256 + 255));
    lv_obj_set_style_local_bg_opa(Object2, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 105);
    lv_obj_set_style_local_border_color(Object2, LV_BTN_PART_MAIN, LV_STATE_DEFAULT,
                                        lv_color_hex(0 * 256 * 256 + 0 * 256 + 0));
    lv_obj_set_style_local_border_opa(Object2, LV_BTN_PART_MAIN, LV_STATE_DEFAULT, 0);

}

