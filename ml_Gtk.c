#define G_SETTINGS_ENABLE_BACKEND
#include <gio/gsettingsbackend.h>
#include <gio/gunixconnection.h>
#include <gio/gunixcredentialsmessage.h>
#include <gio/gunixfdlist.h>
#include <gio/gunixfdmessage.h>
#include <gio/gunixinputstream.h>
#include <gio/gunixmounts.h>
#include <gio/gunixoutputstream.h>
#include <gio/gunixsocketaddress.h>
#include <gtk/gtk.h>
#include <gtk/gtkunixprint.h>
#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/callback.h>
#include <caml/alloc.h>
#include <caml/fail.h>
#include "ml_gobject0.h"

CAMLprim value ml_Gtk_ATContext_get_accessible_role(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_at_context_get_accessible_role(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

void ml_Gtk_ATContext_signal_handler_state_change(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_ATContext_signal_connect_state_change(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "state-change", ml_Gtk_ATContext_signal_handler_state_change, callback);
}

CAMLprim value ml_Gtk_AboutDialog_new() {
  CAMLparam0();
  void * result = gtk_about_dialog_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_AboutDialog_get_license_type(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_about_dialog_get_license_type(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_AboutDialog_get_wrap_license(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_about_dialog_get_wrap_license(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_AboutDialog_set_comments(value instance_, value comments) {
  CAMLparam2(instance_, comments);
  gtk_about_dialog_set_comments(GObject_val(instance_), String_val(comments));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_AboutDialog_set_copyright(value instance_, value copyright) {
  CAMLparam2(instance_, copyright);
  gtk_about_dialog_set_copyright(GObject_val(instance_), String_val(copyright));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_AboutDialog_set_license(value instance_, value license) {
  CAMLparam2(instance_, license);
  gtk_about_dialog_set_license(GObject_val(instance_), String_val(license));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_AboutDialog_set_license_type(value instance_, value license_type) {
  CAMLparam2(instance_, license_type);
  gtk_about_dialog_set_license_type(GObject_val(instance_), Int_val(license_type));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_AboutDialog_set_logo_icon_name(value instance_, value icon_name) {
  CAMLparam2(instance_, icon_name);
  gtk_about_dialog_set_logo_icon_name(GObject_val(instance_), String_val(icon_name));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_AboutDialog_set_program_name(value instance_, value name) {
  CAMLparam2(instance_, name);
  gtk_about_dialog_set_program_name(GObject_val(instance_), String_val(name));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_AboutDialog_set_system_information(value instance_, value system_information) {
  CAMLparam2(instance_, system_information);
  gtk_about_dialog_set_system_information(GObject_val(instance_), String_val(system_information));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_AboutDialog_set_translator_credits(value instance_, value translator_credits) {
  CAMLparam2(instance_, translator_credits);
  gtk_about_dialog_set_translator_credits(GObject_val(instance_), String_val(translator_credits));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_AboutDialog_set_version(value instance_, value version) {
  CAMLparam2(instance_, version);
  gtk_about_dialog_set_version(GObject_val(instance_), String_val(version));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_AboutDialog_set_website(value instance_, value website) {
  CAMLparam2(instance_, website);
  gtk_about_dialog_set_website(GObject_val(instance_), String_val(website));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_AboutDialog_set_website_label(value instance_, value website_label) {
  CAMLparam2(instance_, website_label);
  gtk_about_dialog_set_website_label(GObject_val(instance_), String_val(website_label));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_AboutDialog_set_wrap_license(value instance_, value wrap_license) {
  CAMLparam2(instance_, wrap_license);
  gtk_about_dialog_set_wrap_license(GObject_val(instance_), Bool_val(wrap_license));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ActionBar_new() {
  CAMLparam0();
  void * result = gtk_action_bar_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ActionBar_get_center_widget(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_action_bar_get_center_widget(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ActionBar_get_revealed(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_action_bar_get_revealed(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ActionBar_pack_end(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_action_bar_pack_end(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ActionBar_pack_start(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_action_bar_pack_start(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ActionBar_remove(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_action_bar_remove(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ActionBar_set_center_widget(value instance_, value center_widget) {
  CAMLparam2(instance_, center_widget);
  gtk_action_bar_set_center_widget(GObject_val(instance_), GObject_val(center_widget));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ActionBar_set_revealed(value instance_, value revealed) {
  CAMLparam2(instance_, revealed);
  gtk_action_bar_set_revealed(GObject_val(instance_), Bool_val(revealed));
  CAMLreturn(Val_unit);
}

void ml_Gtk_Adjustment_signal_handler_changed(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Adjustment_signal_connect_changed(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "changed", ml_Gtk_Adjustment_signal_handler_changed, callback);
}

void ml_Gtk_Adjustment_signal_handler_value_changed(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Adjustment_signal_connect_value_changed(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "value-changed", ml_Gtk_Adjustment_signal_handler_value_changed, callback);
}

CAMLprim value ml_Gtk_AlternativeTrigger_get_first(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_alternative_trigger_get_first(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_AlternativeTrigger_get_second(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_alternative_trigger_get_second(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_AnyFilter_new() {
  CAMLparam0();
  void * result = gtk_any_filter_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_AppChooserButton_new(value content_type) {
  CAMLparam1(content_type);
  void * result = gtk_app_chooser_button_new(String_val(content_type));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_AppChooserButton_append_separator(value instance_) {
  CAMLparam1(instance_);
  gtk_app_chooser_button_append_separator(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_AppChooserButton_get_modal(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_app_chooser_button_get_modal(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_AppChooserButton_get_show_default_item(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_app_chooser_button_get_show_default_item(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_AppChooserButton_get_show_dialog_item(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_app_chooser_button_get_show_dialog_item(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_AppChooserButton_set_active_custom_item(value instance_, value name) {
  CAMLparam2(instance_, name);
  gtk_app_chooser_button_set_active_custom_item(GObject_val(instance_), String_val(name));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_AppChooserButton_set_heading(value instance_, value heading) {
  CAMLparam2(instance_, heading);
  gtk_app_chooser_button_set_heading(GObject_val(instance_), String_val(heading));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_AppChooserButton_set_modal(value instance_, value modal) {
  CAMLparam2(instance_, modal);
  gtk_app_chooser_button_set_modal(GObject_val(instance_), Bool_val(modal));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_AppChooserButton_set_show_default_item(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_app_chooser_button_set_show_default_item(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_AppChooserButton_set_show_dialog_item(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_app_chooser_button_set_show_dialog_item(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

void ml_Gtk_AppChooserButton_signal_handler_activate(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_AppChooserButton_signal_connect_activate(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "activate", ml_Gtk_AppChooserButton_signal_handler_activate, callback);
}

void ml_Gtk_AppChooserButton_signal_handler_changed(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_AppChooserButton_signal_connect_changed(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "changed", ml_Gtk_AppChooserButton_signal_handler_changed, callback);
}

CAMLprim value ml_Gtk_AppChooserDialog_new_for_content_type(value parent, value flags, value content_type) {
  CAMLparam3(parent, flags, content_type);
  void * result = gtk_app_chooser_dialog_new_for_content_type(GObject_val(parent), Int_val(flags), String_val(content_type));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_AppChooserDialog_get_widget(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_app_chooser_dialog_get_widget(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_AppChooserDialog_set_heading(value instance_, value heading) {
  CAMLparam2(instance_, heading);
  gtk_app_chooser_dialog_set_heading(GObject_val(instance_), String_val(heading));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_AppChooserWidget_new(value content_type) {
  CAMLparam1(content_type);
  void * result = gtk_app_chooser_widget_new(String_val(content_type));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_AppChooserWidget_get_show_all(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_app_chooser_widget_get_show_all(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_AppChooserWidget_get_show_default(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_app_chooser_widget_get_show_default(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_AppChooserWidget_get_show_fallback(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_app_chooser_widget_get_show_fallback(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_AppChooserWidget_get_show_other(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_app_chooser_widget_get_show_other(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_AppChooserWidget_get_show_recommended(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_app_chooser_widget_get_show_recommended(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_AppChooserWidget_set_default_text(value instance_, value text) {
  CAMLparam2(instance_, text);
  gtk_app_chooser_widget_set_default_text(GObject_val(instance_), String_val(text));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_AppChooserWidget_set_show_all(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_app_chooser_widget_set_show_all(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_AppChooserWidget_set_show_default(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_app_chooser_widget_set_show_default(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_AppChooserWidget_set_show_fallback(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_app_chooser_widget_set_show_fallback(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_AppChooserWidget_set_show_other(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_app_chooser_widget_set_show_other(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_AppChooserWidget_set_show_recommended(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_app_chooser_widget_set_show_recommended(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Application_new(value application_id, value flags) {
  CAMLparam2(application_id, flags);
  void * result = gtk_application_new(String_val(application_id), Int_val(flags));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Application_add_window(value instance_, value window) {
  CAMLparam2(instance_, window);
  gtk_application_add_window(GObject_val(instance_), GObject_val(window));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Application_get_active_window(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_application_get_active_window(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Application_get_menu_by_id(value instance_, value id) {
  CAMLparam2(instance_, id);
  void * result = gtk_application_get_menu_by_id(GObject_val(instance_), String_val(id));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Application_get_menubar(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_application_get_menubar(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Application_get_window_by_id(value instance_, value id) {
  CAMLparam2(instance_, id);
  void * result = gtk_application_get_window_by_id(GObject_val(instance_), Long_val(id));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Application_inhibit(value instance_, value window, value flags, value reason) {
  CAMLparam4(instance_, window, flags, reason);
  guint32 result = gtk_application_inhibit(GObject_val(instance_), GObject_val(window), Int_val(flags), String_val(reason));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Application_remove_window(value instance_, value window) {
  CAMLparam2(instance_, window);
  gtk_application_remove_window(GObject_val(instance_), GObject_val(window));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Application_set_menubar(value instance_, value menubar) {
  CAMLparam2(instance_, menubar);
  gtk_application_set_menubar(GObject_val(instance_), GObject_val(menubar));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Application_uninhibit(value instance_, value cookie) {
  CAMLparam2(instance_, cookie);
  gtk_application_uninhibit(GObject_val(instance_), Long_val(cookie));
  CAMLreturn(Val_unit);
}

void ml_Gtk_Application_signal_handler_query_end(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Application_signal_connect_query_end(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "query-end", ml_Gtk_Application_signal_handler_query_end, callback);
}

void ml_Gtk_Application_signal_handler_window_added(GObject *instance_, void * window, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(window));
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Application_signal_connect_window_added(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "window-added", ml_Gtk_Application_signal_handler_window_added, callback);
}

void ml_Gtk_Application_signal_handler_window_removed(GObject *instance_, void * window, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(window));
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Application_signal_connect_window_removed(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "window-removed", ml_Gtk_Application_signal_handler_window_removed, callback);
}

CAMLprim value ml_Gtk_ApplicationWindow_new(value application) {
  CAMLparam1(application);
  void * result = gtk_application_window_new(GObject_val(application));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ApplicationWindow_get_help_overlay(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_application_window_get_help_overlay(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ApplicationWindow_get_id(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_application_window_get_id(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_ApplicationWindow_get_show_menubar(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_application_window_get_show_menubar(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ApplicationWindow_set_help_overlay(value instance_, value help_overlay) {
  CAMLparam2(instance_, help_overlay);
  gtk_application_window_set_help_overlay(GObject_val(instance_), GObject_val(help_overlay));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ApplicationWindow_set_show_menubar(value instance_, value show_menubar) {
  CAMLparam2(instance_, show_menubar);
  gtk_application_window_set_show_menubar(GObject_val(instance_), Bool_val(show_menubar));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_AspectFrame_get_child(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_aspect_frame_get_child(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_AspectFrame_get_obey_child(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_aspect_frame_get_obey_child(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_AspectFrame_set_child(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_aspect_frame_set_child(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_AspectFrame_set_obey_child(value instance_, value obey_child) {
  CAMLparam2(instance_, obey_child);
  gtk_aspect_frame_set_obey_child(GObject_val(instance_), Bool_val(obey_child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Assistant_new() {
  CAMLparam0();
  void * result = gtk_assistant_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Assistant_add_action_widget(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_assistant_add_action_widget(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Assistant_append_page(value instance_, value page) {
  CAMLparam2(instance_, page);
  gint32 result = gtk_assistant_append_page(GObject_val(instance_), GObject_val(page));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Assistant_commit(value instance_) {
  CAMLparam1(instance_);
  gtk_assistant_commit(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Assistant_get_current_page(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_assistant_get_current_page(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Assistant_get_n_pages(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_assistant_get_n_pages(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Assistant_get_nth_page(value instance_, value page_num) {
  CAMLparam2(instance_, page_num);
  void * result = gtk_assistant_get_nth_page(GObject_val(instance_), Long_val(page_num));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Assistant_get_page(value instance_, value child) {
  CAMLparam2(instance_, child);
  void * result = gtk_assistant_get_page(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Assistant_get_page_complete(value instance_, value page) {
  CAMLparam2(instance_, page);
  gboolean result = gtk_assistant_get_page_complete(GObject_val(instance_), GObject_val(page));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Assistant_get_page_type(value instance_, value page) {
  CAMLparam2(instance_, page);
  int result = gtk_assistant_get_page_type(GObject_val(instance_), GObject_val(page));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_Assistant_insert_page(value instance_, value page, value position) {
  CAMLparam3(instance_, page, position);
  gint32 result = gtk_assistant_insert_page(GObject_val(instance_), GObject_val(page), Long_val(position));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Assistant_next_page(value instance_) {
  CAMLparam1(instance_);
  gtk_assistant_next_page(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Assistant_prepend_page(value instance_, value page) {
  CAMLparam2(instance_, page);
  gint32 result = gtk_assistant_prepend_page(GObject_val(instance_), GObject_val(page));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Assistant_previous_page(value instance_) {
  CAMLparam1(instance_);
  gtk_assistant_previous_page(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Assistant_remove_action_widget(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_assistant_remove_action_widget(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Assistant_remove_page(value instance_, value page_num) {
  CAMLparam2(instance_, page_num);
  gtk_assistant_remove_page(GObject_val(instance_), Long_val(page_num));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Assistant_set_current_page(value instance_, value page_num) {
  CAMLparam2(instance_, page_num);
  gtk_assistant_set_current_page(GObject_val(instance_), Long_val(page_num));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Assistant_set_page_complete(value instance_, value page, value complete) {
  CAMLparam3(instance_, page, complete);
  gtk_assistant_set_page_complete(GObject_val(instance_), GObject_val(page), Bool_val(complete));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Assistant_set_page_title(value instance_, value page, value title) {
  CAMLparam3(instance_, page, title);
  gtk_assistant_set_page_title(GObject_val(instance_), GObject_val(page), String_val(title));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Assistant_set_page_type(value instance_, value page, value type) {
  CAMLparam3(instance_, page, type);
  gtk_assistant_set_page_type(GObject_val(instance_), GObject_val(page), Int_val(type));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Assistant_update_buttons_state(value instance_) {
  CAMLparam1(instance_);
  gtk_assistant_update_buttons_state(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

void ml_Gtk_Assistant_signal_handler_apply(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Assistant_signal_connect_apply(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "apply", ml_Gtk_Assistant_signal_handler_apply, callback);
}

void ml_Gtk_Assistant_signal_handler_cancel(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Assistant_signal_connect_cancel(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "cancel", ml_Gtk_Assistant_signal_handler_cancel, callback);
}

void ml_Gtk_Assistant_signal_handler_close(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Assistant_signal_connect_close(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "close", ml_Gtk_Assistant_signal_handler_close, callback);
}

void ml_Gtk_Assistant_signal_handler_escape(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Assistant_signal_connect_escape(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "escape", ml_Gtk_Assistant_signal_handler_escape, callback);
}

void ml_Gtk_Assistant_signal_handler_prepare(GObject *instance_, void * page, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(page));
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Assistant_signal_connect_prepare(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "prepare", ml_Gtk_Assistant_signal_handler_prepare, callback);
}

CAMLprim value ml_Gtk_AssistantPage_get_child(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_assistant_page_get_child(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_BinLayout_new() {
  CAMLparam0();
  void * result = gtk_bin_layout_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_BookmarkList_get_io_priority(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_bookmark_list_get_io_priority(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_BookmarkList_is_loading(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_bookmark_list_is_loading(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_BookmarkList_set_attributes(value instance_, value attributes) {
  CAMLparam2(instance_, attributes);
  gtk_bookmark_list_set_attributes(GObject_val(instance_), String_val(attributes));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_BookmarkList_set_io_priority(value instance_, value io_priority) {
  CAMLparam2(instance_, io_priority);
  gtk_bookmark_list_set_io_priority(GObject_val(instance_), Long_val(io_priority));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_BoolFilter_get_invert(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_bool_filter_get_invert(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_BoolFilter_set_invert(value instance_, value invert) {
  CAMLparam2(instance_, invert);
  gtk_bool_filter_set_invert(GObject_val(instance_), Bool_val(invert));
  CAMLreturn(Val_unit);
}

int ml_enum_orientation_to_int(value in) {
  switch (Int_val(in)) {
    case 0: return GTK_ORIENTATION_HORIZONTAL;
    case 1: return GTK_ORIENTATION_VERTICAL;
    default: caml_invalid_argument("orientation was unknown enumerated value");
  }
}

CAMLprim value ml_Gtk_Box_new(value orientation, value spacing) {
  CAMLparam2(orientation, spacing);
  void * result = gtk_box_new(ml_enum_orientation_to_int(orientation), Long_val(spacing));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Box_append(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_box_append(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Box_get_baseline_position(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_box_get_baseline_position(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_Box_get_homogeneous(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_box_get_homogeneous(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Box_get_spacing(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_box_get_spacing(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Box_insert_child_after(value instance_, value child, value sibling) {
  CAMLparam3(instance_, child, sibling);
  gtk_box_insert_child_after(GObject_val(instance_), GObject_val(child), GObject_val(sibling));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Box_prepend(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_box_prepend(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Box_remove(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_box_remove(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Box_reorder_child_after(value instance_, value child, value sibling) {
  CAMLparam3(instance_, child, sibling);
  gtk_box_reorder_child_after(GObject_val(instance_), GObject_val(child), GObject_val(sibling));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Box_set_baseline_position(value instance_, value position) {
  CAMLparam2(instance_, position);
  gtk_box_set_baseline_position(GObject_val(instance_), Int_val(position));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Box_set_homogeneous(value instance_, value homogeneous) {
  CAMLparam2(instance_, homogeneous);
  gtk_box_set_homogeneous(GObject_val(instance_), Bool_val(homogeneous));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Box_set_spacing(value instance_, value spacing) {
  CAMLparam2(instance_, spacing);
  gtk_box_set_spacing(GObject_val(instance_), Long_val(spacing));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_BoxLayout_new(value orientation) {
  CAMLparam1(orientation);
  void * result = gtk_box_layout_new(Int_val(orientation));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_BoxLayout_get_baseline_position(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_box_layout_get_baseline_position(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_BoxLayout_get_homogeneous(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_box_layout_get_homogeneous(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_BoxLayout_get_spacing(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_box_layout_get_spacing(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_BoxLayout_set_baseline_position(value instance_, value position) {
  CAMLparam2(instance_, position);
  gtk_box_layout_set_baseline_position(GObject_val(instance_), Int_val(position));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_BoxLayout_set_homogeneous(value instance_, value homogeneous) {
  CAMLparam2(instance_, homogeneous);
  gtk_box_layout_set_homogeneous(GObject_val(instance_), Bool_val(homogeneous));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_BoxLayout_set_spacing(value instance_, value spacing) {
  CAMLparam2(instance_, spacing);
  gtk_box_layout_set_spacing(GObject_val(instance_), Long_val(spacing));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Builder_new() {
  CAMLparam0();
  void * result = gtk_builder_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Builder_new_from_resource(value resource_path) {
  CAMLparam1(resource_path);
  void * result = gtk_builder_new_from_resource(String_val(resource_path));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Builder_add_from_resource(value instance_, value resource_path) {
  CAMLparam2(instance_, resource_path);
  CAMLlocal1(exn_msg);
  GError *err = NULL;
  gboolean result = gtk_builder_add_from_resource(GObject_val(instance_), String_val(resource_path), &err);
  if (err) { exn_msg = caml_copy_string(err->message); g_error_free(err); caml_failwith_value(exn_msg); }
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Builder_expose_object(value instance_, value name, value object) {
  CAMLparam3(instance_, name, object);
  gtk_builder_expose_object(GObject_val(instance_), String_val(name), GObject_val(object));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Builder_get_current_object(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_builder_get_current_object(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Builder_get_object(value instance_, value name) {
  CAMLparam2(instance_, name);
  void * result = gtk_builder_get_object(GObject_val(instance_), String_val(name));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Builder_set_current_object(value instance_, value current_object) {
  CAMLparam2(instance_, current_object);
  gtk_builder_set_current_object(GObject_val(instance_), GObject_val(current_object));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Builder_set_translation_domain(value instance_, value domain) {
  CAMLparam2(instance_, domain);
  gtk_builder_set_translation_domain(GObject_val(instance_), String_val(domain));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_BuilderCScope_new() {
  CAMLparam0();
  void * result = gtk_builder_cscope_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Button_new() {
  CAMLparam0();
  void * result = gtk_button_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Button_new_from_icon_name(value icon_name) {
  CAMLparam1(icon_name);
  void * result = gtk_button_new_from_icon_name(String_val(icon_name));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Button_new_with_label(value label) {
  CAMLparam1(label);
  void * result = gtk_button_new_with_label(String_val(label));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Button_new_with_mnemonic(value label) {
  CAMLparam1(label);
  void * result = gtk_button_new_with_mnemonic(String_val(label));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Button_get_child(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_button_get_child(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Button_get_has_frame(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_button_get_has_frame(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Button_get_use_underline(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_button_get_use_underline(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Button_set_child(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_button_set_child(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Button_set_has_frame(value instance_, value has_frame) {
  CAMLparam2(instance_, has_frame);
  gtk_button_set_has_frame(GObject_val(instance_), Bool_val(has_frame));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Button_set_icon_name(value instance_, value icon_name) {
  CAMLparam2(instance_, icon_name);
  gtk_button_set_icon_name(GObject_val(instance_), String_val(icon_name));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Button_set_label(value instance_, value label) {
  CAMLparam2(instance_, label);
  gtk_button_set_label(GObject_val(instance_), String_val(label));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Button_set_use_underline(value instance_, value use_underline) {
  CAMLparam2(instance_, use_underline);
  gtk_button_set_use_underline(GObject_val(instance_), Bool_val(use_underline));
  CAMLreturn(Val_unit);
}

void ml_Gtk_Button_signal_handler_activate(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Button_signal_connect_activate(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "activate", ml_Gtk_Button_signal_handler_activate, callback);
}

void ml_Gtk_Button_signal_handler_clicked(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Button_signal_connect_clicked(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "clicked", ml_Gtk_Button_signal_handler_clicked, callback);
}

CAMLprim value ml_Gtk_Calendar_new() {
  CAMLparam0();
  void * result = gtk_calendar_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Calendar_clear_marks(value instance_) {
  CAMLparam1(instance_);
  gtk_calendar_clear_marks(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Calendar_get_day_is_marked(value instance_, value day) {
  CAMLparam2(instance_, day);
  gboolean result = gtk_calendar_get_day_is_marked(GObject_val(instance_), Long_val(day));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Calendar_get_show_day_names(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_calendar_get_show_day_names(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Calendar_get_show_heading(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_calendar_get_show_heading(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Calendar_get_show_week_numbers(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_calendar_get_show_week_numbers(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Calendar_mark_day(value instance_, value day) {
  CAMLparam2(instance_, day);
  gtk_calendar_mark_day(GObject_val(instance_), Long_val(day));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Calendar_set_show_day_names(value instance_, value _value) {
  CAMLparam2(instance_, _value);
  gtk_calendar_set_show_day_names(GObject_val(instance_), Bool_val(_value));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Calendar_set_show_heading(value instance_, value _value) {
  CAMLparam2(instance_, _value);
  gtk_calendar_set_show_heading(GObject_val(instance_), Bool_val(_value));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Calendar_set_show_week_numbers(value instance_, value _value) {
  CAMLparam2(instance_, _value);
  gtk_calendar_set_show_week_numbers(GObject_val(instance_), Bool_val(_value));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Calendar_unmark_day(value instance_, value day) {
  CAMLparam2(instance_, day);
  gtk_calendar_unmark_day(GObject_val(instance_), Long_val(day));
  CAMLreturn(Val_unit);
}

void ml_Gtk_Calendar_signal_handler_day_selected(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Calendar_signal_connect_day_selected(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "day-selected", ml_Gtk_Calendar_signal_handler_day_selected, callback);
}

void ml_Gtk_Calendar_signal_handler_next_month(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Calendar_signal_connect_next_month(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "next-month", ml_Gtk_Calendar_signal_handler_next_month, callback);
}

void ml_Gtk_Calendar_signal_handler_next_year(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Calendar_signal_connect_next_year(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "next-year", ml_Gtk_Calendar_signal_handler_next_year, callback);
}

void ml_Gtk_Calendar_signal_handler_prev_month(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Calendar_signal_connect_prev_month(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "prev-month", ml_Gtk_Calendar_signal_handler_prev_month, callback);
}

void ml_Gtk_Calendar_signal_handler_prev_year(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Calendar_signal_connect_prev_year(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "prev-year", ml_Gtk_Calendar_signal_handler_prev_year, callback);
}

CAMLprim value ml_Gtk_CellArea_add(value instance_, value renderer) {
  CAMLparam2(instance_, renderer);
  gtk_cell_area_add(GObject_val(instance_), GObject_val(renderer));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CellArea_add_focus_sibling(value instance_, value renderer, value sibling) {
  CAMLparam3(instance_, renderer, sibling);
  gtk_cell_area_add_focus_sibling(GObject_val(instance_), GObject_val(renderer), GObject_val(sibling));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CellArea_attribute_connect(value instance_, value renderer, value attribute, value column) {
  CAMLparam4(instance_, renderer, attribute, column);
  gtk_cell_area_attribute_connect(GObject_val(instance_), GObject_val(renderer), String_val(attribute), Long_val(column));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CellArea_attribute_disconnect(value instance_, value renderer, value attribute) {
  CAMLparam3(instance_, renderer, attribute);
  gtk_cell_area_attribute_disconnect(GObject_val(instance_), GObject_val(renderer), String_val(attribute));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CellArea_attribute_get_column(value instance_, value renderer, value attribute) {
  CAMLparam3(instance_, renderer, attribute);
  gint32 result = gtk_cell_area_attribute_get_column(GObject_val(instance_), GObject_val(renderer), String_val(attribute));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_CellArea_copy_context(value instance_, value context) {
  CAMLparam2(instance_, context);
  void * result = gtk_cell_area_copy_context(GObject_val(instance_), GObject_val(context));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CellArea_create_context(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_cell_area_create_context(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CellArea_focus(value instance_, value direction) {
  CAMLparam2(instance_, direction);
  gboolean result = gtk_cell_area_focus(GObject_val(instance_), Int_val(direction));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_CellArea_get_edited_cell(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_cell_area_get_edited_cell(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CellArea_get_focus_cell(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_cell_area_get_focus_cell(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CellArea_get_focus_from_sibling(value instance_, value renderer) {
  CAMLparam2(instance_, renderer);
  void * result = gtk_cell_area_get_focus_from_sibling(GObject_val(instance_), GObject_val(renderer));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CellArea_get_request_mode(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_cell_area_get_request_mode(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_CellArea_has_renderer(value instance_, value renderer) {
  CAMLparam2(instance_, renderer);
  gboolean result = gtk_cell_area_has_renderer(GObject_val(instance_), GObject_val(renderer));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_CellArea_is_activatable(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_cell_area_is_activatable(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_CellArea_is_focus_sibling(value instance_, value renderer, value sibling) {
  CAMLparam3(instance_, renderer, sibling);
  gboolean result = gtk_cell_area_is_focus_sibling(GObject_val(instance_), GObject_val(renderer), GObject_val(sibling));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_CellArea_remove(value instance_, value renderer) {
  CAMLparam2(instance_, renderer);
  gtk_cell_area_remove(GObject_val(instance_), GObject_val(renderer));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CellArea_remove_focus_sibling(value instance_, value renderer, value sibling) {
  CAMLparam3(instance_, renderer, sibling);
  gtk_cell_area_remove_focus_sibling(GObject_val(instance_), GObject_val(renderer), GObject_val(sibling));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CellArea_set_focus_cell(value instance_, value renderer) {
  CAMLparam2(instance_, renderer);
  gtk_cell_area_set_focus_cell(GObject_val(instance_), GObject_val(renderer));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CellArea_stop_editing(value instance_, value canceled) {
  CAMLparam2(instance_, canceled);
  gtk_cell_area_stop_editing(GObject_val(instance_), Bool_val(canceled));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CellAreaBox_new() {
  CAMLparam0();
  void * result = gtk_cell_area_box_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CellAreaBox_get_spacing(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_cell_area_box_get_spacing(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_CellAreaBox_pack_end(value instance_, value renderer, value expand, value align, value fixed) {
  CAMLparam5(instance_, renderer, expand, align, fixed);
  gtk_cell_area_box_pack_end(GObject_val(instance_), GObject_val(renderer), Bool_val(expand), Bool_val(align), Bool_val(fixed));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CellAreaBox_pack_start(value instance_, value renderer, value expand, value align, value fixed) {
  CAMLparam5(instance_, renderer, expand, align, fixed);
  gtk_cell_area_box_pack_start(GObject_val(instance_), GObject_val(renderer), Bool_val(expand), Bool_val(align), Bool_val(fixed));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CellAreaBox_set_spacing(value instance_, value spacing) {
  CAMLparam2(instance_, spacing);
  gtk_cell_area_box_set_spacing(GObject_val(instance_), Long_val(spacing));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CellAreaContext_allocate(value instance_, value width, value height) {
  CAMLparam3(instance_, width, height);
  gtk_cell_area_context_allocate(GObject_val(instance_), Long_val(width), Long_val(height));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CellAreaContext_get_area(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_cell_area_context_get_area(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CellAreaContext_push_preferred_height(value instance_, value minimum_height, value natural_height) {
  CAMLparam3(instance_, minimum_height, natural_height);
  gtk_cell_area_context_push_preferred_height(GObject_val(instance_), Long_val(minimum_height), Long_val(natural_height));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CellAreaContext_push_preferred_width(value instance_, value minimum_width, value natural_width) {
  CAMLparam3(instance_, minimum_width, natural_width);
  gtk_cell_area_context_push_preferred_width(GObject_val(instance_), Long_val(minimum_width), Long_val(natural_width));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CellAreaContext_reset(value instance_) {
  CAMLparam1(instance_);
  gtk_cell_area_context_reset(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CellRenderer_get_is_expanded(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_cell_renderer_get_is_expanded(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_CellRenderer_get_is_expander(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_cell_renderer_get_is_expander(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_CellRenderer_get_request_mode(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_cell_renderer_get_request_mode(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_CellRenderer_get_sensitive(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_cell_renderer_get_sensitive(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_CellRenderer_get_visible(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_cell_renderer_get_visible(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_CellRenderer_is_activatable(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_cell_renderer_is_activatable(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_CellRenderer_set_fixed_size(value instance_, value width, value height) {
  CAMLparam3(instance_, width, height);
  gtk_cell_renderer_set_fixed_size(GObject_val(instance_), Long_val(width), Long_val(height));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CellRenderer_set_is_expanded(value instance_, value is_expanded) {
  CAMLparam2(instance_, is_expanded);
  gtk_cell_renderer_set_is_expanded(GObject_val(instance_), Bool_val(is_expanded));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CellRenderer_set_is_expander(value instance_, value is_expander) {
  CAMLparam2(instance_, is_expander);
  gtk_cell_renderer_set_is_expander(GObject_val(instance_), Bool_val(is_expander));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CellRenderer_set_padding(value instance_, value xpad, value ypad) {
  CAMLparam3(instance_, xpad, ypad);
  gtk_cell_renderer_set_padding(GObject_val(instance_), Long_val(xpad), Long_val(ypad));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CellRenderer_set_sensitive(value instance_, value sensitive) {
  CAMLparam2(instance_, sensitive);
  gtk_cell_renderer_set_sensitive(GObject_val(instance_), Bool_val(sensitive));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CellRenderer_set_visible(value instance_, value visible) {
  CAMLparam2(instance_, visible);
  gtk_cell_renderer_set_visible(GObject_val(instance_), Bool_val(visible));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CellRenderer_stop_editing(value instance_, value canceled) {
  CAMLparam2(instance_, canceled);
  gtk_cell_renderer_stop_editing(GObject_val(instance_), Bool_val(canceled));
  CAMLreturn(Val_unit);
}

void ml_Gtk_CellRenderer_signal_handler_editing_canceled(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_CellRenderer_signal_connect_editing_canceled(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "editing-canceled", ml_Gtk_CellRenderer_signal_handler_editing_canceled, callback);
}

CAMLprim value ml_Gtk_CellRendererAccel_new() {
  CAMLparam0();
  void * result = gtk_cell_renderer_accel_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CellRendererCombo_new() {
  CAMLparam0();
  void * result = gtk_cell_renderer_combo_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CellRendererPixbuf_new() {
  CAMLparam0();
  void * result = gtk_cell_renderer_pixbuf_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CellRendererProgress_new() {
  CAMLparam0();
  void * result = gtk_cell_renderer_progress_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CellRendererSpin_new() {
  CAMLparam0();
  void * result = gtk_cell_renderer_spin_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CellRendererSpinner_new() {
  CAMLparam0();
  void * result = gtk_cell_renderer_spinner_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CellRendererText_new() {
  CAMLparam0();
  void * result = gtk_cell_renderer_text_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CellRendererText_set_fixed_height_from_font(value instance_, value number_of_rows) {
  CAMLparam2(instance_, number_of_rows);
  gtk_cell_renderer_text_set_fixed_height_from_font(GObject_val(instance_), Long_val(number_of_rows));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CellRendererToggle_new() {
  CAMLparam0();
  void * result = gtk_cell_renderer_toggle_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CellRendererToggle_get_activatable(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_cell_renderer_toggle_get_activatable(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_CellRendererToggle_get_active(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_cell_renderer_toggle_get_active(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_CellRendererToggle_get_radio(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_cell_renderer_toggle_get_radio(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_CellRendererToggle_set_activatable(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_cell_renderer_toggle_set_activatable(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CellRendererToggle_set_active(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_cell_renderer_toggle_set_active(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CellRendererToggle_set_radio(value instance_, value radio) {
  CAMLparam2(instance_, radio);
  gtk_cell_renderer_toggle_set_radio(GObject_val(instance_), Bool_val(radio));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CellView_new() {
  CAMLparam0();
  void * result = gtk_cell_view_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CellView_new_with_context(value area, value context) {
  CAMLparam2(area, context);
  void * result = gtk_cell_view_new_with_context(GObject_val(area), GObject_val(context));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CellView_new_with_markup(value markup) {
  CAMLparam1(markup);
  void * result = gtk_cell_view_new_with_markup(String_val(markup));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CellView_new_with_text(value text) {
  CAMLparam1(text);
  void * result = gtk_cell_view_new_with_text(String_val(text));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CellView_new_with_texture(value texture) {
  CAMLparam1(texture);
  void * result = gtk_cell_view_new_with_texture(GObject_val(texture));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CellView_get_draw_sensitive(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_cell_view_get_draw_sensitive(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_CellView_get_fit_model(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_cell_view_get_fit_model(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_CellView_set_draw_sensitive(value instance_, value draw_sensitive) {
  CAMLparam2(instance_, draw_sensitive);
  gtk_cell_view_set_draw_sensitive(GObject_val(instance_), Bool_val(draw_sensitive));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CellView_set_fit_model(value instance_, value fit_model) {
  CAMLparam2(instance_, fit_model);
  gtk_cell_view_set_fit_model(GObject_val(instance_), Bool_val(fit_model));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CenterBox_new() {
  CAMLparam0();
  void * result = gtk_center_box_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CenterBox_get_baseline_position(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_center_box_get_baseline_position(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_CenterBox_get_center_widget(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_center_box_get_center_widget(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CenterBox_get_end_widget(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_center_box_get_end_widget(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CenterBox_get_start_widget(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_center_box_get_start_widget(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CenterBox_set_baseline_position(value instance_, value position) {
  CAMLparam2(instance_, position);
  gtk_center_box_set_baseline_position(GObject_val(instance_), Int_val(position));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CenterBox_set_center_widget(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_center_box_set_center_widget(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CenterBox_set_end_widget(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_center_box_set_end_widget(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CenterBox_set_start_widget(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_center_box_set_start_widget(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CenterLayout_new() {
  CAMLparam0();
  void * result = gtk_center_layout_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CenterLayout_get_baseline_position(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_center_layout_get_baseline_position(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_CenterLayout_get_center_widget(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_center_layout_get_center_widget(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CenterLayout_get_end_widget(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_center_layout_get_end_widget(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CenterLayout_get_orientation(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_center_layout_get_orientation(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_CenterLayout_get_start_widget(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_center_layout_get_start_widget(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CenterLayout_set_baseline_position(value instance_, value baseline_position) {
  CAMLparam2(instance_, baseline_position);
  gtk_center_layout_set_baseline_position(GObject_val(instance_), Int_val(baseline_position));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CenterLayout_set_center_widget(value instance_, value widget) {
  CAMLparam2(instance_, widget);
  gtk_center_layout_set_center_widget(GObject_val(instance_), GObject_val(widget));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CenterLayout_set_end_widget(value instance_, value widget) {
  CAMLparam2(instance_, widget);
  gtk_center_layout_set_end_widget(GObject_val(instance_), GObject_val(widget));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CenterLayout_set_orientation(value instance_, value orientation) {
  CAMLparam2(instance_, orientation);
  gtk_center_layout_set_orientation(GObject_val(instance_), Int_val(orientation));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CenterLayout_set_start_widget(value instance_, value widget) {
  CAMLparam2(instance_, widget);
  gtk_center_layout_set_start_widget(GObject_val(instance_), GObject_val(widget));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CheckButton_new() {
  CAMLparam0();
  void * result = gtk_check_button_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CheckButton_new_with_label(value label) {
  CAMLparam1(label);
  void * result = gtk_check_button_new_with_label(String_val(label));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CheckButton_new_with_mnemonic(value label) {
  CAMLparam1(label);
  void * result = gtk_check_button_new_with_mnemonic(String_val(label));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CheckButton_get_active(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_check_button_get_active(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_CheckButton_get_inconsistent(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_check_button_get_inconsistent(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_CheckButton_get_use_underline(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_check_button_get_use_underline(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_CheckButton_set_active(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_check_button_set_active(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CheckButton_set_group(value instance_, value group) {
  CAMLparam2(instance_, group);
  gtk_check_button_set_group(GObject_val(instance_), GObject_val(group));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CheckButton_set_inconsistent(value instance_, value inconsistent) {
  CAMLparam2(instance_, inconsistent);
  gtk_check_button_set_inconsistent(GObject_val(instance_), Bool_val(inconsistent));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CheckButton_set_label(value instance_, value label) {
  CAMLparam2(instance_, label);
  gtk_check_button_set_label(GObject_val(instance_), String_val(label));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CheckButton_set_use_underline(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_check_button_set_use_underline(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

void ml_Gtk_CheckButton_signal_handler_activate(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_CheckButton_signal_connect_activate(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "activate", ml_Gtk_CheckButton_signal_handler_activate, callback);
}

void ml_Gtk_CheckButton_signal_handler_toggled(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_CheckButton_signal_connect_toggled(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "toggled", ml_Gtk_CheckButton_signal_handler_toggled, callback);
}

CAMLprim value ml_Gtk_ColorButton_new() {
  CAMLparam0();
  void * result = gtk_color_button_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ColorButton_get_modal(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_color_button_get_modal(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ColorButton_set_modal(value instance_, value modal) {
  CAMLparam2(instance_, modal);
  gtk_color_button_set_modal(GObject_val(instance_), Bool_val(modal));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ColorButton_set_title(value instance_, value title) {
  CAMLparam2(instance_, title);
  gtk_color_button_set_title(GObject_val(instance_), String_val(title));
  CAMLreturn(Val_unit);
}

void ml_Gtk_ColorButton_signal_handler_activate(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_ColorButton_signal_connect_activate(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "activate", ml_Gtk_ColorButton_signal_handler_activate, callback);
}

void ml_Gtk_ColorButton_signal_handler_color_set(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_ColorButton_signal_connect_color_set(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "color-set", ml_Gtk_ColorButton_signal_handler_color_set, callback);
}

CAMLprim value ml_Gtk_ColorChooserDialog_new(value title, value parent) {
  CAMLparam2(title, parent);
  void * result = gtk_color_chooser_dialog_new(String_val(title), GObject_val(parent));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ColorChooserWidget_new() {
  CAMLparam0();
  void * result = gtk_color_chooser_widget_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ColumnView_append_column(value instance_, value column) {
  CAMLparam2(instance_, column);
  gtk_column_view_append_column(GObject_val(instance_), GObject_val(column));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ColumnView_get_enable_rubberband(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_column_view_get_enable_rubberband(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ColumnView_get_reorderable(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_column_view_get_reorderable(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ColumnView_get_show_column_separators(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_column_view_get_show_column_separators(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ColumnView_get_show_row_separators(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_column_view_get_show_row_separators(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ColumnView_get_single_click_activate(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_column_view_get_single_click_activate(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ColumnView_get_sorter(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_column_view_get_sorter(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ColumnView_insert_column(value instance_, value position, value column) {
  CAMLparam3(instance_, position, column);
  gtk_column_view_insert_column(GObject_val(instance_), Long_val(position), GObject_val(column));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ColumnView_remove_column(value instance_, value column) {
  CAMLparam2(instance_, column);
  gtk_column_view_remove_column(GObject_val(instance_), GObject_val(column));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ColumnView_set_enable_rubberband(value instance_, value enable_rubberband) {
  CAMLparam2(instance_, enable_rubberband);
  gtk_column_view_set_enable_rubberband(GObject_val(instance_), Bool_val(enable_rubberband));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ColumnView_set_reorderable(value instance_, value reorderable) {
  CAMLparam2(instance_, reorderable);
  gtk_column_view_set_reorderable(GObject_val(instance_), Bool_val(reorderable));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ColumnView_set_show_column_separators(value instance_, value show_column_separators) {
  CAMLparam2(instance_, show_column_separators);
  gtk_column_view_set_show_column_separators(GObject_val(instance_), Bool_val(show_column_separators));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ColumnView_set_show_row_separators(value instance_, value show_row_separators) {
  CAMLparam2(instance_, show_row_separators);
  gtk_column_view_set_show_row_separators(GObject_val(instance_), Bool_val(show_row_separators));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ColumnView_set_single_click_activate(value instance_, value single_click_activate) {
  CAMLparam2(instance_, single_click_activate);
  gtk_column_view_set_single_click_activate(GObject_val(instance_), Bool_val(single_click_activate));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ColumnView_sort_by_column(value instance_, value column, value direction) {
  CAMLparam3(instance_, column, direction);
  gtk_column_view_sort_by_column(GObject_val(instance_), GObject_val(column), Int_val(direction));
  CAMLreturn(Val_unit);
}

void ml_Gtk_ColumnView_signal_handler_activate(GObject *instance_, guint32 position, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_long(position);
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_ColumnView_signal_connect_activate(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "activate", ml_Gtk_ColumnView_signal_handler_activate, callback);
}

CAMLprim value ml_Gtk_ColumnViewColumn_get_column_view(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_column_view_column_get_column_view(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ColumnViewColumn_get_expand(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_column_view_column_get_expand(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ColumnViewColumn_get_factory(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_column_view_column_get_factory(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ColumnViewColumn_get_fixed_width(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_column_view_column_get_fixed_width(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_ColumnViewColumn_get_header_menu(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_column_view_column_get_header_menu(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ColumnViewColumn_get_resizable(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_column_view_column_get_resizable(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ColumnViewColumn_get_sorter(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_column_view_column_get_sorter(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ColumnViewColumn_get_visible(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_column_view_column_get_visible(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ColumnViewColumn_set_expand(value instance_, value expand) {
  CAMLparam2(instance_, expand);
  gtk_column_view_column_set_expand(GObject_val(instance_), Bool_val(expand));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ColumnViewColumn_set_factory(value instance_, value factory) {
  CAMLparam2(instance_, factory);
  gtk_column_view_column_set_factory(GObject_val(instance_), GObject_val(factory));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ColumnViewColumn_set_fixed_width(value instance_, value fixed_width) {
  CAMLparam2(instance_, fixed_width);
  gtk_column_view_column_set_fixed_width(GObject_val(instance_), Long_val(fixed_width));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ColumnViewColumn_set_header_menu(value instance_, value menu) {
  CAMLparam2(instance_, menu);
  gtk_column_view_column_set_header_menu(GObject_val(instance_), GObject_val(menu));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ColumnViewColumn_set_resizable(value instance_, value resizable) {
  CAMLparam2(instance_, resizable);
  gtk_column_view_column_set_resizable(GObject_val(instance_), Bool_val(resizable));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ColumnViewColumn_set_sorter(value instance_, value sorter) {
  CAMLparam2(instance_, sorter);
  gtk_column_view_column_set_sorter(GObject_val(instance_), GObject_val(sorter));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ColumnViewColumn_set_title(value instance_, value title) {
  CAMLparam2(instance_, title);
  gtk_column_view_column_set_title(GObject_val(instance_), String_val(title));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ColumnViewColumn_set_visible(value instance_, value visible) {
  CAMLparam2(instance_, visible);
  gtk_column_view_column_set_visible(GObject_val(instance_), Bool_val(visible));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ComboBox_new() {
  CAMLparam0();
  void * result = gtk_combo_box_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ComboBox_new_with_entry() {
  CAMLparam0();
  void * result = gtk_combo_box_new_with_entry();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ComboBox_get_active(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_combo_box_get_active(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_ComboBox_get_button_sensitivity(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_combo_box_get_button_sensitivity(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_ComboBox_get_child(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_combo_box_get_child(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ComboBox_get_entry_text_column(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_combo_box_get_entry_text_column(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_ComboBox_get_has_entry(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_combo_box_get_has_entry(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ComboBox_get_id_column(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_combo_box_get_id_column(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_ComboBox_get_popup_fixed_width(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_combo_box_get_popup_fixed_width(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ComboBox_popdown(value instance_) {
  CAMLparam1(instance_);
  gtk_combo_box_popdown(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ComboBox_popup(value instance_) {
  CAMLparam1(instance_);
  gtk_combo_box_popup(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ComboBox_popup_for_device(value instance_, value device) {
  CAMLparam2(instance_, device);
  gtk_combo_box_popup_for_device(GObject_val(instance_), GObject_val(device));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ComboBox_set_active(value instance_, value index_) {
  CAMLparam2(instance_, index_);
  gtk_combo_box_set_active(GObject_val(instance_), Long_val(index_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ComboBox_set_active_id(value instance_, value active_id) {
  CAMLparam2(instance_, active_id);
  gboolean result = gtk_combo_box_set_active_id(GObject_val(instance_), String_val(active_id));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ComboBox_set_button_sensitivity(value instance_, value sensitivity) {
  CAMLparam2(instance_, sensitivity);
  gtk_combo_box_set_button_sensitivity(GObject_val(instance_), Int_val(sensitivity));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ComboBox_set_child(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_combo_box_set_child(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ComboBox_set_entry_text_column(value instance_, value text_column) {
  CAMLparam2(instance_, text_column);
  gtk_combo_box_set_entry_text_column(GObject_val(instance_), Long_val(text_column));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ComboBox_set_id_column(value instance_, value id_column) {
  CAMLparam2(instance_, id_column);
  gtk_combo_box_set_id_column(GObject_val(instance_), Long_val(id_column));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ComboBox_set_popup_fixed_width(value instance_, value fixed) {
  CAMLparam2(instance_, fixed);
  gtk_combo_box_set_popup_fixed_width(GObject_val(instance_), Bool_val(fixed));
  CAMLreturn(Val_unit);
}

void ml_Gtk_ComboBox_signal_handler_activate(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_ComboBox_signal_connect_activate(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "activate", ml_Gtk_ComboBox_signal_handler_activate, callback);
}

void ml_Gtk_ComboBox_signal_handler_changed(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_ComboBox_signal_connect_changed(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "changed", ml_Gtk_ComboBox_signal_handler_changed, callback);
}

void ml_Gtk_ComboBox_signal_handler_move_active(GObject *instance_, int scroll_type, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_int(scroll_type);
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_ComboBox_signal_connect_move_active(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "move-active", ml_Gtk_ComboBox_signal_handler_move_active, callback);
}

gboolean ml_Gtk_ComboBox_signal_handler_popdown(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_ComboBox_signal_connect_popdown(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "popdown", ml_Gtk_ComboBox_signal_handler_popdown, callback);
}

void ml_Gtk_ComboBox_signal_handler_popup(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_ComboBox_signal_connect_popup(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "popup", ml_Gtk_ComboBox_signal_handler_popup, callback);
}

CAMLprim value ml_Gtk_ComboBoxText_new() {
  CAMLparam0();
  void * result = gtk_combo_box_text_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ComboBoxText_new_with_entry() {
  CAMLparam0();
  void * result = gtk_combo_box_text_new_with_entry();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ComboBoxText_append(value instance_, value id, value text) {
  CAMLparam3(instance_, id, text);
  gtk_combo_box_text_append(GObject_val(instance_), String_val(id), String_val(text));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ComboBoxText_append_text(value instance_, value text) {
  CAMLparam2(instance_, text);
  gtk_combo_box_text_append_text(GObject_val(instance_), String_val(text));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ComboBoxText_insert(value instance_, value position, value id, value text) {
  CAMLparam4(instance_, position, id, text);
  gtk_combo_box_text_insert(GObject_val(instance_), Long_val(position), String_val(id), String_val(text));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ComboBoxText_insert_text(value instance_, value position, value text) {
  CAMLparam3(instance_, position, text);
  gtk_combo_box_text_insert_text(GObject_val(instance_), Long_val(position), String_val(text));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ComboBoxText_prepend(value instance_, value id, value text) {
  CAMLparam3(instance_, id, text);
  gtk_combo_box_text_prepend(GObject_val(instance_), String_val(id), String_val(text));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ComboBoxText_prepend_text(value instance_, value text) {
  CAMLparam2(instance_, text);
  gtk_combo_box_text_prepend_text(GObject_val(instance_), String_val(text));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ComboBoxText_remove(value instance_, value position) {
  CAMLparam2(instance_, position);
  gtk_combo_box_text_remove(GObject_val(instance_), Long_val(position));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ComboBoxText_remove_all(value instance_) {
  CAMLparam1(instance_);
  gtk_combo_box_text_remove_all(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Constraint_get_relation(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_constraint_get_relation(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_Constraint_get_source_attribute(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_constraint_get_source_attribute(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_Constraint_get_strength(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_constraint_get_strength(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Constraint_get_target_attribute(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_constraint_get_target_attribute(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_Constraint_is_attached(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_constraint_is_attached(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Constraint_is_constant(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_constraint_is_constant(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Constraint_is_required(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_constraint_is_required(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ConstraintGuide_new() {
  CAMLparam0();
  void * result = gtk_constraint_guide_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ConstraintGuide_get_strength(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_constraint_guide_get_strength(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_ConstraintGuide_set_max_size(value instance_, value width, value height) {
  CAMLparam3(instance_, width, height);
  gtk_constraint_guide_set_max_size(GObject_val(instance_), Long_val(width), Long_val(height));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ConstraintGuide_set_min_size(value instance_, value width, value height) {
  CAMLparam3(instance_, width, height);
  gtk_constraint_guide_set_min_size(GObject_val(instance_), Long_val(width), Long_val(height));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ConstraintGuide_set_name(value instance_, value name) {
  CAMLparam2(instance_, name);
  gtk_constraint_guide_set_name(GObject_val(instance_), String_val(name));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ConstraintGuide_set_nat_size(value instance_, value width, value height) {
  CAMLparam3(instance_, width, height);
  gtk_constraint_guide_set_nat_size(GObject_val(instance_), Long_val(width), Long_val(height));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ConstraintGuide_set_strength(value instance_, value strength) {
  CAMLparam2(instance_, strength);
  gtk_constraint_guide_set_strength(GObject_val(instance_), Int_val(strength));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ConstraintLayout_new() {
  CAMLparam0();
  void * result = gtk_constraint_layout_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ConstraintLayout_remove_all_constraints(value instance_) {
  CAMLparam1(instance_);
  gtk_constraint_layout_remove_all_constraints(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ConstraintLayout_remove_constraint(value instance_, value constraint) {
  CAMLparam2(instance_, constraint);
  gtk_constraint_layout_remove_constraint(GObject_val(instance_), GObject_val(constraint));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ConstraintLayout_remove_guide(value instance_, value guide) {
  CAMLparam2(instance_, guide);
  gtk_constraint_layout_remove_guide(GObject_val(instance_), GObject_val(guide));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CssProvider_new() {
  CAMLparam0();
  void * result = gtk_css_provider_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_CssProvider_load_from_resource(value instance_, value resource_path) {
  CAMLparam2(instance_, resource_path);
  gtk_css_provider_load_from_resource(GObject_val(instance_), String_val(resource_path));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_CssProvider_load_named(value instance_, value name, value variant) {
  CAMLparam3(instance_, name, variant);
  gtk_css_provider_load_named(GObject_val(instance_), String_val(name), String_val(variant));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Dialog_new() {
  CAMLparam0();
  void * result = gtk_dialog_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Dialog_add_action_widget(value instance_, value child, value response_id) {
  CAMLparam3(instance_, child, response_id);
  gtk_dialog_add_action_widget(GObject_val(instance_), GObject_val(child), Long_val(response_id));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Dialog_add_button(value instance_, value button_text, value response_id) {
  CAMLparam3(instance_, button_text, response_id);
  void * result = gtk_dialog_add_button(GObject_val(instance_), String_val(button_text), Long_val(response_id));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Dialog_get_content_area(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_dialog_get_content_area(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Dialog_get_header_bar(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_dialog_get_header_bar(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Dialog_get_response_for_widget(value instance_, value widget) {
  CAMLparam2(instance_, widget);
  gint32 result = gtk_dialog_get_response_for_widget(GObject_val(instance_), GObject_val(widget));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Dialog_get_widget_for_response(value instance_, value response_id) {
  CAMLparam2(instance_, response_id);
  void * result = gtk_dialog_get_widget_for_response(GObject_val(instance_), Long_val(response_id));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Dialog_response(value instance_, value response_id) {
  CAMLparam2(instance_, response_id);
  gtk_dialog_response(GObject_val(instance_), Long_val(response_id));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Dialog_set_default_response(value instance_, value response_id) {
  CAMLparam2(instance_, response_id);
  gtk_dialog_set_default_response(GObject_val(instance_), Long_val(response_id));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Dialog_set_response_sensitive(value instance_, value response_id, value setting) {
  CAMLparam3(instance_, response_id, setting);
  gtk_dialog_set_response_sensitive(GObject_val(instance_), Long_val(response_id), Bool_val(setting));
  CAMLreturn(Val_unit);
}

void ml_Gtk_Dialog_signal_handler_close(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Dialog_signal_connect_close(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "close", ml_Gtk_Dialog_signal_handler_close, callback);
}

void ml_Gtk_Dialog_signal_handler_response(GObject *instance_, gint32 response_id, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_long(response_id);
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Dialog_signal_connect_response(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "response", ml_Gtk_Dialog_signal_handler_response, callback);
}

CAMLprim value ml_Gtk_DirectoryList_get_io_priority(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_directory_list_get_io_priority(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_DirectoryList_get_monitored(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_directory_list_get_monitored(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_DirectoryList_is_loading(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_directory_list_is_loading(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_DirectoryList_set_attributes(value instance_, value attributes) {
  CAMLparam2(instance_, attributes);
  gtk_directory_list_set_attributes(GObject_val(instance_), String_val(attributes));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_DirectoryList_set_io_priority(value instance_, value io_priority) {
  CAMLparam2(instance_, io_priority);
  gtk_directory_list_set_io_priority(GObject_val(instance_), Long_val(io_priority));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_DirectoryList_set_monitored(value instance_, value monitored) {
  CAMLparam2(instance_, monitored);
  gtk_directory_list_set_monitored(GObject_val(instance_), Bool_val(monitored));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_DragIcon_get_child(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_drag_icon_get_child(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_DragIcon_set_child(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_drag_icon_set_child(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_DragSource_new() {
  CAMLparam0();
  void * result = gtk_drag_source_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_DragSource_drag_cancel(value instance_) {
  CAMLparam1(instance_);
  gtk_drag_source_drag_cancel(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_DragSource_get_content(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_drag_source_get_content(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_DragSource_get_drag(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_drag_source_get_drag(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_DragSource_set_actions(value instance_, value actions) {
  CAMLparam2(instance_, actions);
  gtk_drag_source_set_actions(GObject_val(instance_), Int_val(actions));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_DragSource_set_content(value instance_, value content) {
  CAMLparam2(instance_, content);
  gtk_drag_source_set_content(GObject_val(instance_), GObject_val(content));
  CAMLreturn(Val_unit);
}

void ml_Gtk_DragSource_signal_handler_drag_begin(GObject *instance_, void * drag, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(drag));
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_DragSource_signal_connect_drag_begin(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "drag-begin", ml_Gtk_DragSource_signal_handler_drag_begin, callback);
}

gboolean ml_Gtk_DragSource_signal_handler_drag_cancel(GObject *instance_, void * drag, int reason, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 2);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(drag));
  args[1] = Val_int(reason);
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 2, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_DragSource_signal_connect_drag_cancel(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "drag-cancel", ml_Gtk_DragSource_signal_handler_drag_cancel, callback);
}

void ml_Gtk_DragSource_signal_handler_drag_end(GObject *instance_, void * drag, gboolean delete_data, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 2);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(drag));
  args[1] = (delete_data ? Val_true : Val_false);
  ;caml_callbackN(*callbackCell, 2, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_DragSource_signal_connect_drag_end(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "drag-end", ml_Gtk_DragSource_signal_handler_drag_end, callback);
}

CAMLprim value ml_Gtk_DrawingArea_new() {
  CAMLparam0();
  void * result = gtk_drawing_area_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_DrawingArea_get_content_height(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_drawing_area_get_content_height(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_DrawingArea_get_content_width(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_drawing_area_get_content_width(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_DrawingArea_set_content_height(value instance_, value height) {
  CAMLparam2(instance_, height);
  gtk_drawing_area_set_content_height(GObject_val(instance_), Long_val(height));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_DrawingArea_set_content_width(value instance_, value width) {
  CAMLparam2(instance_, width);
  gtk_drawing_area_set_content_width(GObject_val(instance_), Long_val(width));
  CAMLreturn(Val_unit);
}

void ml_Gtk_DrawingArea_signal_handler_resize(GObject *instance_, gint32 width, gint32 height, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 2);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_long(width);
  args[1] = Val_long(height);
  ;caml_callbackN(*callbackCell, 2, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_DrawingArea_signal_connect_resize(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "resize", ml_Gtk_DrawingArea_signal_handler_resize, callback);
}

CAMLprim value ml_Gtk_DropControllerMotion_new() {
  CAMLparam0();
  void * result = gtk_drop_controller_motion_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_DropControllerMotion_contains_pointer(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_drop_controller_motion_contains_pointer(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_DropControllerMotion_get_drop(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_drop_controller_motion_get_drop(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_DropControllerMotion_is_pointer(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_drop_controller_motion_is_pointer(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

void ml_Gtk_DropControllerMotion_signal_handler_leave(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_DropControllerMotion_signal_connect_leave(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "leave", ml_Gtk_DropControllerMotion_signal_handler_leave, callback);
}

CAMLprim value ml_Gtk_DropDown_get_enable_search(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_drop_down_get_enable_search(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_DropDown_get_factory(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_drop_down_get_factory(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_DropDown_get_list_factory(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_drop_down_get_list_factory(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_DropDown_get_selected(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_drop_down_get_selected(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_DropDown_get_selected_item(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_drop_down_get_selected_item(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_DropDown_get_show_arrow(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_drop_down_get_show_arrow(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_DropDown_set_enable_search(value instance_, value enable_search) {
  CAMLparam2(instance_, enable_search);
  gtk_drop_down_set_enable_search(GObject_val(instance_), Bool_val(enable_search));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_DropDown_set_factory(value instance_, value factory) {
  CAMLparam2(instance_, factory);
  gtk_drop_down_set_factory(GObject_val(instance_), GObject_val(factory));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_DropDown_set_list_factory(value instance_, value factory) {
  CAMLparam2(instance_, factory);
  gtk_drop_down_set_list_factory(GObject_val(instance_), GObject_val(factory));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_DropDown_set_selected(value instance_, value position) {
  CAMLparam2(instance_, position);
  gtk_drop_down_set_selected(GObject_val(instance_), Long_val(position));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_DropDown_set_show_arrow(value instance_, value show_arrow) {
  CAMLparam2(instance_, show_arrow);
  gtk_drop_down_set_show_arrow(GObject_val(instance_), Bool_val(show_arrow));
  CAMLreturn(Val_unit);
}

void ml_Gtk_DropDown_signal_handler_activate(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_DropDown_signal_connect_activate(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "activate", ml_Gtk_DropDown_signal_handler_activate, callback);
}

CAMLprim value ml_Gtk_DropTarget_get_current_drop(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_drop_target_get_current_drop(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_DropTarget_get_drop(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_drop_target_get_drop(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_DropTarget_get_preload(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_drop_target_get_preload(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_DropTarget_reject(value instance_) {
  CAMLparam1(instance_);
  gtk_drop_target_reject(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_DropTarget_set_actions(value instance_, value actions) {
  CAMLparam2(instance_, actions);
  gtk_drop_target_set_actions(GObject_val(instance_), Int_val(actions));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_DropTarget_set_preload(value instance_, value preload) {
  CAMLparam2(instance_, preload);
  gtk_drop_target_set_preload(GObject_val(instance_), Bool_val(preload));
  CAMLreturn(Val_unit);
}

gboolean ml_Gtk_DropTarget_signal_handler_accept(GObject *instance_, void * drop, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(drop));
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_DropTarget_signal_connect_accept(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "accept", ml_Gtk_DropTarget_signal_handler_accept, callback);
}

void ml_Gtk_DropTarget_signal_handler_leave(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_DropTarget_signal_connect_leave(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "leave", ml_Gtk_DropTarget_signal_handler_leave, callback);
}

CAMLprim value ml_Gtk_DropTargetAsync_reject_drop(value instance_, value drop) {
  CAMLparam2(instance_, drop);
  gtk_drop_target_async_reject_drop(GObject_val(instance_), GObject_val(drop));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_DropTargetAsync_set_actions(value instance_, value actions) {
  CAMLparam2(instance_, actions);
  gtk_drop_target_async_set_actions(GObject_val(instance_), Int_val(actions));
  CAMLreturn(Val_unit);
}

gboolean ml_Gtk_DropTargetAsync_signal_handler_accept(GObject *instance_, void * drop, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(drop));
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_DropTargetAsync_signal_connect_accept(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "accept", ml_Gtk_DropTargetAsync_signal_handler_accept, callback);
}

void ml_Gtk_DropTargetAsync_signal_handler_drag_leave(GObject *instance_, void * drop, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(drop));
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_DropTargetAsync_signal_connect_drag_leave(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "drag-leave", ml_Gtk_DropTargetAsync_signal_handler_drag_leave, callback);
}

CAMLprim value ml_Gtk_EditableLabel_new(value str) {
  CAMLparam1(str);
  void * result = gtk_editable_label_new(String_val(str));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_EditableLabel_get_editing(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_editable_label_get_editing(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_EditableLabel_start_editing(value instance_) {
  CAMLparam1(instance_);
  gtk_editable_label_start_editing(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_EditableLabel_stop_editing(value instance_, value commit) {
  CAMLparam2(instance_, commit);
  gtk_editable_label_stop_editing(GObject_val(instance_), Bool_val(commit));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_EmojiChooser_new() {
  CAMLparam0();
  void * result = gtk_emoji_chooser_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Entry_new() {
  CAMLparam0();
  void * result = gtk_entry_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Entry_new_with_buffer(value buffer) {
  CAMLparam1(buffer);
  void * result = gtk_entry_new_with_buffer(GObject_val(buffer));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Entry_get_activates_default(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_entry_get_activates_default(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Entry_get_buffer(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_entry_get_buffer(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Entry_get_completion(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_entry_get_completion(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Entry_get_current_icon_drag_source(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_entry_get_current_icon_drag_source(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Entry_get_extra_menu(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_entry_get_extra_menu(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Entry_get_has_frame(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_entry_get_has_frame(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Entry_get_icon_activatable(value instance_, value icon_pos) {
  CAMLparam2(instance_, icon_pos);
  gboolean result = gtk_entry_get_icon_activatable(GObject_val(instance_), Int_val(icon_pos));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Entry_get_icon_at_pos(value instance_, value x, value y) {
  CAMLparam3(instance_, x, y);
  gint32 result = gtk_entry_get_icon_at_pos(GObject_val(instance_), Long_val(x), Long_val(y));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Entry_get_icon_sensitive(value instance_, value icon_pos) {
  CAMLparam2(instance_, icon_pos);
  gboolean result = gtk_entry_get_icon_sensitive(GObject_val(instance_), Int_val(icon_pos));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Entry_get_icon_storage_type(value instance_, value icon_pos) {
  CAMLparam2(instance_, icon_pos);
  int result = gtk_entry_get_icon_storage_type(GObject_val(instance_), Int_val(icon_pos));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_Entry_get_input_purpose(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_entry_get_input_purpose(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_Entry_get_max_length(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_entry_get_max_length(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Entry_get_overwrite_mode(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_entry_get_overwrite_mode(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Entry_get_visibility(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_entry_get_visibility(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Entry_grab_focus_without_selecting(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_entry_grab_focus_without_selecting(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Entry_progress_pulse(value instance_) {
  CAMLparam1(instance_);
  gtk_entry_progress_pulse(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Entry_reset_im_context(value instance_) {
  CAMLparam1(instance_);
  gtk_entry_reset_im_context(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Entry_set_activates_default(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_entry_set_activates_default(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Entry_set_buffer(value instance_, value buffer) {
  CAMLparam2(instance_, buffer);
  gtk_entry_set_buffer(GObject_val(instance_), GObject_val(buffer));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Entry_set_completion(value instance_, value completion) {
  CAMLparam2(instance_, completion);
  gtk_entry_set_completion(GObject_val(instance_), GObject_val(completion));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Entry_set_extra_menu(value instance_, value model) {
  CAMLparam2(instance_, model);
  gtk_entry_set_extra_menu(GObject_val(instance_), GObject_val(model));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Entry_set_has_frame(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_entry_set_has_frame(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Entry_set_icon_activatable(value instance_, value icon_pos, value activatable) {
  CAMLparam3(instance_, icon_pos, activatable);
  gtk_entry_set_icon_activatable(GObject_val(instance_), Int_val(icon_pos), Bool_val(activatable));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Entry_set_icon_drag_source(value instance_, value icon_pos, value provider, value actions) {
  CAMLparam4(instance_, icon_pos, provider, actions);
  gtk_entry_set_icon_drag_source(GObject_val(instance_), Int_val(icon_pos), GObject_val(provider), Int_val(actions));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Entry_set_icon_from_icon_name(value instance_, value icon_pos, value icon_name) {
  CAMLparam3(instance_, icon_pos, icon_name);
  gtk_entry_set_icon_from_icon_name(GObject_val(instance_), Int_val(icon_pos), String_val(icon_name));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Entry_set_icon_sensitive(value instance_, value icon_pos, value sensitive) {
  CAMLparam3(instance_, icon_pos, sensitive);
  gtk_entry_set_icon_sensitive(GObject_val(instance_), Int_val(icon_pos), Bool_val(sensitive));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Entry_set_icon_tooltip_markup(value instance_, value icon_pos, value tooltip) {
  CAMLparam3(instance_, icon_pos, tooltip);
  gtk_entry_set_icon_tooltip_markup(GObject_val(instance_), Int_val(icon_pos), String_val(tooltip));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Entry_set_icon_tooltip_text(value instance_, value icon_pos, value tooltip) {
  CAMLparam3(instance_, icon_pos, tooltip);
  gtk_entry_set_icon_tooltip_text(GObject_val(instance_), Int_val(icon_pos), String_val(tooltip));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Entry_set_input_hints(value instance_, value hints) {
  CAMLparam2(instance_, hints);
  gtk_entry_set_input_hints(GObject_val(instance_), Int_val(hints));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Entry_set_input_purpose(value instance_, value purpose) {
  CAMLparam2(instance_, purpose);
  gtk_entry_set_input_purpose(GObject_val(instance_), Int_val(purpose));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Entry_set_max_length(value instance_, value max) {
  CAMLparam2(instance_, max);
  gtk_entry_set_max_length(GObject_val(instance_), Long_val(max));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Entry_set_overwrite_mode(value instance_, value overwrite) {
  CAMLparam2(instance_, overwrite);
  gtk_entry_set_overwrite_mode(GObject_val(instance_), Bool_val(overwrite));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Entry_set_placeholder_text(value instance_, value text) {
  CAMLparam2(instance_, text);
  gtk_entry_set_placeholder_text(GObject_val(instance_), String_val(text));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Entry_set_visibility(value instance_, value visible) {
  CAMLparam2(instance_, visible);
  gtk_entry_set_visibility(GObject_val(instance_), Bool_val(visible));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Entry_unset_invisible_char(value instance_) {
  CAMLparam1(instance_);
  gtk_entry_unset_invisible_char(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

void ml_Gtk_Entry_signal_handler_activate(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Entry_signal_connect_activate(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "activate", ml_Gtk_Entry_signal_handler_activate, callback);
}

void ml_Gtk_Entry_signal_handler_icon_press(GObject *instance_, int icon_pos, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_int(icon_pos);
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Entry_signal_connect_icon_press(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "icon-press", ml_Gtk_Entry_signal_handler_icon_press, callback);
}

void ml_Gtk_Entry_signal_handler_icon_release(GObject *instance_, int icon_pos, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_int(icon_pos);
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Entry_signal_connect_icon_release(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "icon-release", ml_Gtk_Entry_signal_handler_icon_release, callback);
}

CAMLprim value ml_Gtk_EntryBuffer_new(value initial_chars, value n_initial_chars) {
  CAMLparam2(initial_chars, n_initial_chars);
  void * result = gtk_entry_buffer_new(String_val(initial_chars), Long_val(n_initial_chars));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_EntryBuffer_delete_text(value instance_, value position, value n_chars) {
  CAMLparam3(instance_, position, n_chars);
  guint32 result = gtk_entry_buffer_delete_text(GObject_val(instance_), Long_val(position), Long_val(n_chars));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_EntryBuffer_emit_deleted_text(value instance_, value position, value n_chars) {
  CAMLparam3(instance_, position, n_chars);
  gtk_entry_buffer_emit_deleted_text(GObject_val(instance_), Long_val(position), Long_val(n_chars));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_EntryBuffer_emit_inserted_text(value instance_, value position, value chars, value n_chars) {
  CAMLparam4(instance_, position, chars, n_chars);
  gtk_entry_buffer_emit_inserted_text(GObject_val(instance_), Long_val(position), String_val(chars), Long_val(n_chars));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_EntryBuffer_get_length(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_entry_buffer_get_length(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_EntryBuffer_get_max_length(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_entry_buffer_get_max_length(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_EntryBuffer_insert_text(value instance_, value position, value chars, value n_chars) {
  CAMLparam4(instance_, position, chars, n_chars);
  guint32 result = gtk_entry_buffer_insert_text(GObject_val(instance_), Long_val(position), String_val(chars), Long_val(n_chars));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_EntryBuffer_set_max_length(value instance_, value max_length) {
  CAMLparam2(instance_, max_length);
  gtk_entry_buffer_set_max_length(GObject_val(instance_), Long_val(max_length));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_EntryBuffer_set_text(value instance_, value chars, value n_chars) {
  CAMLparam3(instance_, chars, n_chars);
  gtk_entry_buffer_set_text(GObject_val(instance_), String_val(chars), Long_val(n_chars));
  CAMLreturn(Val_unit);
}

void ml_Gtk_EntryBuffer_signal_handler_deleted_text(GObject *instance_, guint32 position, guint32 n_chars, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 2);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_long(position);
  args[1] = Val_long(n_chars);
  ;caml_callbackN(*callbackCell, 2, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_EntryBuffer_signal_connect_deleted_text(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "deleted-text", ml_Gtk_EntryBuffer_signal_handler_deleted_text, callback);
}

CAMLprim value ml_Gtk_EntryCompletion_new() {
  CAMLparam0();
  void * result = gtk_entry_completion_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_EntryCompletion_new_with_area(value area) {
  CAMLparam1(area);
  void * result = gtk_entry_completion_new_with_area(GObject_val(area));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_EntryCompletion_complete(value instance_) {
  CAMLparam1(instance_);
  gtk_entry_completion_complete(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_EntryCompletion_get_entry(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_entry_completion_get_entry(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_EntryCompletion_get_inline_completion(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_entry_completion_get_inline_completion(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_EntryCompletion_get_inline_selection(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_entry_completion_get_inline_selection(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_EntryCompletion_get_minimum_key_length(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_entry_completion_get_minimum_key_length(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_EntryCompletion_get_popup_completion(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_entry_completion_get_popup_completion(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_EntryCompletion_get_popup_set_width(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_entry_completion_get_popup_set_width(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_EntryCompletion_get_popup_single_match(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_entry_completion_get_popup_single_match(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_EntryCompletion_get_text_column(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_entry_completion_get_text_column(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_EntryCompletion_insert_prefix(value instance_) {
  CAMLparam1(instance_);
  gtk_entry_completion_insert_prefix(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_EntryCompletion_set_inline_completion(value instance_, value inline_completion) {
  CAMLparam2(instance_, inline_completion);
  gtk_entry_completion_set_inline_completion(GObject_val(instance_), Bool_val(inline_completion));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_EntryCompletion_set_inline_selection(value instance_, value inline_selection) {
  CAMLparam2(instance_, inline_selection);
  gtk_entry_completion_set_inline_selection(GObject_val(instance_), Bool_val(inline_selection));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_EntryCompletion_set_minimum_key_length(value instance_, value length) {
  CAMLparam2(instance_, length);
  gtk_entry_completion_set_minimum_key_length(GObject_val(instance_), Long_val(length));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_EntryCompletion_set_popup_completion(value instance_, value popup_completion) {
  CAMLparam2(instance_, popup_completion);
  gtk_entry_completion_set_popup_completion(GObject_val(instance_), Bool_val(popup_completion));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_EntryCompletion_set_popup_set_width(value instance_, value popup_set_width) {
  CAMLparam2(instance_, popup_set_width);
  gtk_entry_completion_set_popup_set_width(GObject_val(instance_), Bool_val(popup_set_width));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_EntryCompletion_set_popup_single_match(value instance_, value popup_single_match) {
  CAMLparam2(instance_, popup_single_match);
  gtk_entry_completion_set_popup_single_match(GObject_val(instance_), Bool_val(popup_single_match));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_EntryCompletion_set_text_column(value instance_, value column) {
  CAMLparam2(instance_, column);
  gtk_entry_completion_set_text_column(GObject_val(instance_), Long_val(column));
  CAMLreturn(Val_unit);
}

void ml_Gtk_EntryCompletion_signal_handler_no_matches(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_EntryCompletion_signal_connect_no_matches(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "no-matches", ml_Gtk_EntryCompletion_signal_handler_no_matches, callback);
}

CAMLprim value ml_Gtk_EventController_get_current_event_device(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_event_controller_get_current_event_device(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_EventController_get_current_event_time(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_event_controller_get_current_event_time(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_EventController_get_propagation_limit(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_event_controller_get_propagation_limit(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_EventController_get_propagation_phase(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_event_controller_get_propagation_phase(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_EventController_get_widget(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_event_controller_get_widget(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_EventController_reset(value instance_) {
  CAMLparam1(instance_);
  gtk_event_controller_reset(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_EventController_set_name(value instance_, value name) {
  CAMLparam2(instance_, name);
  gtk_event_controller_set_name(GObject_val(instance_), String_val(name));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_EventController_set_propagation_limit(value instance_, value limit) {
  CAMLparam2(instance_, limit);
  gtk_event_controller_set_propagation_limit(GObject_val(instance_), Int_val(limit));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_EventController_set_propagation_phase(value instance_, value phase) {
  CAMLparam2(instance_, phase);
  gtk_event_controller_set_propagation_phase(GObject_val(instance_), Int_val(phase));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_EventControllerFocus_new() {
  CAMLparam0();
  void * result = gtk_event_controller_focus_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_EventControllerFocus_contains_focus(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_event_controller_focus_contains_focus(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_EventControllerFocus_is_focus(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_event_controller_focus_is_focus(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

void ml_Gtk_EventControllerFocus_signal_handler_enter(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_EventControllerFocus_signal_connect_enter(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "enter", ml_Gtk_EventControllerFocus_signal_handler_enter, callback);
}

void ml_Gtk_EventControllerFocus_signal_handler_leave(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_EventControllerFocus_signal_connect_leave(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "leave", ml_Gtk_EventControllerFocus_signal_handler_leave, callback);
}

CAMLprim value ml_Gtk_EventControllerKey_new() {
  CAMLparam0();
  void * result = gtk_event_controller_key_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_EventControllerKey_forward(value instance_, value widget) {
  CAMLparam2(instance_, widget);
  gboolean result = gtk_event_controller_key_forward(GObject_val(instance_), GObject_val(widget));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_EventControllerKey_get_group(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_event_controller_key_get_group(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_EventControllerKey_get_im_context(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_event_controller_key_get_im_context(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_EventControllerKey_set_im_context(value instance_, value im_context) {
  CAMLparam2(instance_, im_context);
  gtk_event_controller_key_set_im_context(GObject_val(instance_), GObject_val(im_context));
  CAMLreturn(Val_unit);
}

void ml_Gtk_EventControllerKey_signal_handler_im_update(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_EventControllerKey_signal_connect_im_update(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "im-update", ml_Gtk_EventControllerKey_signal_handler_im_update, callback);
}

CAMLprim value ml_Gtk_EventControllerLegacy_new() {
  CAMLparam0();
  void * result = gtk_event_controller_legacy_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_EventControllerMotion_new() {
  CAMLparam0();
  void * result = gtk_event_controller_motion_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_EventControllerMotion_contains_pointer(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_event_controller_motion_contains_pointer(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_EventControllerMotion_is_pointer(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_event_controller_motion_is_pointer(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

void ml_Gtk_EventControllerMotion_signal_handler_leave(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_EventControllerMotion_signal_connect_leave(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "leave", ml_Gtk_EventControllerMotion_signal_handler_leave, callback);
}

CAMLprim value ml_Gtk_EventControllerScroll_new(value flags) {
  CAMLparam1(flags);
  void * result = gtk_event_controller_scroll_new(Int_val(flags));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_EventControllerScroll_set_flags(value instance_, value flags) {
  CAMLparam2(instance_, flags);
  gtk_event_controller_scroll_set_flags(GObject_val(instance_), Int_val(flags));
  CAMLreturn(Val_unit);
}

void ml_Gtk_EventControllerScroll_signal_handler_scroll_begin(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_EventControllerScroll_signal_connect_scroll_begin(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "scroll-begin", ml_Gtk_EventControllerScroll_signal_handler_scroll_begin, callback);
}

void ml_Gtk_EventControllerScroll_signal_handler_scroll_end(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_EventControllerScroll_signal_connect_scroll_end(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "scroll-end", ml_Gtk_EventControllerScroll_signal_handler_scroll_end, callback);
}

CAMLprim value ml_Gtk_EveryFilter_new() {
  CAMLparam0();
  void * result = gtk_every_filter_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Expander_new(value label) {
  CAMLparam1(label);
  void * result = gtk_expander_new(String_val(label));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Expander_new_with_mnemonic(value label) {
  CAMLparam1(label);
  void * result = gtk_expander_new_with_mnemonic(String_val(label));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Expander_get_child(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_expander_get_child(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Expander_get_expanded(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_expander_get_expanded(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Expander_get_label_widget(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_expander_get_label_widget(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Expander_get_resize_toplevel(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_expander_get_resize_toplevel(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Expander_get_use_markup(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_expander_get_use_markup(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Expander_get_use_underline(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_expander_get_use_underline(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Expander_set_child(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_expander_set_child(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Expander_set_expanded(value instance_, value expanded) {
  CAMLparam2(instance_, expanded);
  gtk_expander_set_expanded(GObject_val(instance_), Bool_val(expanded));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Expander_set_label(value instance_, value label) {
  CAMLparam2(instance_, label);
  gtk_expander_set_label(GObject_val(instance_), String_val(label));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Expander_set_label_widget(value instance_, value label_widget) {
  CAMLparam2(instance_, label_widget);
  gtk_expander_set_label_widget(GObject_val(instance_), GObject_val(label_widget));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Expander_set_resize_toplevel(value instance_, value resize_toplevel) {
  CAMLparam2(instance_, resize_toplevel);
  gtk_expander_set_resize_toplevel(GObject_val(instance_), Bool_val(resize_toplevel));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Expander_set_use_markup(value instance_, value use_markup) {
  CAMLparam2(instance_, use_markup);
  gtk_expander_set_use_markup(GObject_val(instance_), Bool_val(use_markup));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Expander_set_use_underline(value instance_, value use_underline) {
  CAMLparam2(instance_, use_underline);
  gtk_expander_set_use_underline(GObject_val(instance_), Bool_val(use_underline));
  CAMLreturn(Val_unit);
}

void ml_Gtk_Expander_signal_handler_activate(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Expander_signal_connect_activate(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "activate", ml_Gtk_Expander_signal_handler_activate, callback);
}

CAMLprim value ml_Gtk_FileChooserNative_new(value title, value parent, value action, value accept_label, value cancel_label) {
  CAMLparam5(title, parent, action, accept_label, cancel_label);
  void * result = gtk_file_chooser_native_new(String_val(title), GObject_val(parent), Int_val(action), String_val(accept_label), String_val(cancel_label));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_FileChooserNative_set_accept_label(value instance_, value accept_label) {
  CAMLparam2(instance_, accept_label);
  gtk_file_chooser_native_set_accept_label(GObject_val(instance_), String_val(accept_label));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_FileChooserNative_set_cancel_label(value instance_, value cancel_label) {
  CAMLparam2(instance_, cancel_label);
  gtk_file_chooser_native_set_cancel_label(GObject_val(instance_), String_val(cancel_label));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_FileChooserWidget_new(value action) {
  CAMLparam1(action);
  void * result = gtk_file_chooser_widget_new(Int_val(action));
  CAMLreturn(Val_GObject((void *)(result)));
}

void ml_Gtk_FileChooserWidget_signal_handler_desktop_folder(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_FileChooserWidget_signal_connect_desktop_folder(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "desktop-folder", ml_Gtk_FileChooserWidget_signal_handler_desktop_folder, callback);
}

void ml_Gtk_FileChooserWidget_signal_handler_down_folder(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_FileChooserWidget_signal_connect_down_folder(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "down-folder", ml_Gtk_FileChooserWidget_signal_handler_down_folder, callback);
}

void ml_Gtk_FileChooserWidget_signal_handler_home_folder(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_FileChooserWidget_signal_connect_home_folder(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "home-folder", ml_Gtk_FileChooserWidget_signal_handler_home_folder, callback);
}

void ml_Gtk_FileChooserWidget_signal_handler_location_popup_on_paste(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_FileChooserWidget_signal_connect_location_popup_on_paste(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "location-popup-on-paste", ml_Gtk_FileChooserWidget_signal_handler_location_popup_on_paste, callback);
}

void ml_Gtk_FileChooserWidget_signal_handler_location_toggle_popup(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_FileChooserWidget_signal_connect_location_toggle_popup(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "location-toggle-popup", ml_Gtk_FileChooserWidget_signal_handler_location_toggle_popup, callback);
}

void ml_Gtk_FileChooserWidget_signal_handler_places_shortcut(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_FileChooserWidget_signal_connect_places_shortcut(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "places-shortcut", ml_Gtk_FileChooserWidget_signal_handler_places_shortcut, callback);
}

void ml_Gtk_FileChooserWidget_signal_handler_quick_bookmark(GObject *instance_, gint32 bookmark_index, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_long(bookmark_index);
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_FileChooserWidget_signal_connect_quick_bookmark(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "quick-bookmark", ml_Gtk_FileChooserWidget_signal_handler_quick_bookmark, callback);
}

void ml_Gtk_FileChooserWidget_signal_handler_recent_shortcut(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_FileChooserWidget_signal_connect_recent_shortcut(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "recent-shortcut", ml_Gtk_FileChooserWidget_signal_handler_recent_shortcut, callback);
}

void ml_Gtk_FileChooserWidget_signal_handler_search_shortcut(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_FileChooserWidget_signal_connect_search_shortcut(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "search-shortcut", ml_Gtk_FileChooserWidget_signal_handler_search_shortcut, callback);
}

void ml_Gtk_FileChooserWidget_signal_handler_show_hidden(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_FileChooserWidget_signal_connect_show_hidden(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "show-hidden", ml_Gtk_FileChooserWidget_signal_handler_show_hidden, callback);
}

void ml_Gtk_FileChooserWidget_signal_handler_up_folder(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_FileChooserWidget_signal_connect_up_folder(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "up-folder", ml_Gtk_FileChooserWidget_signal_handler_up_folder, callback);
}

CAMLprim value ml_Gtk_FileFilter_new() {
  CAMLparam0();
  void * result = gtk_file_filter_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_FileFilter_add_mime_type(value instance_, value mime_type) {
  CAMLparam2(instance_, mime_type);
  gtk_file_filter_add_mime_type(GObject_val(instance_), String_val(mime_type));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_FileFilter_add_pattern(value instance_, value pattern) {
  CAMLparam2(instance_, pattern);
  gtk_file_filter_add_pattern(GObject_val(instance_), String_val(pattern));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_FileFilter_add_pixbuf_formats(value instance_) {
  CAMLparam1(instance_);
  gtk_file_filter_add_pixbuf_formats(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_FileFilter_add_suffix(value instance_, value suffix) {
  CAMLparam2(instance_, suffix);
  gtk_file_filter_add_suffix(GObject_val(instance_), String_val(suffix));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_FileFilter_set_name(value instance_, value name) {
  CAMLparam2(instance_, name);
  gtk_file_filter_set_name(GObject_val(instance_), String_val(name));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Filter_changed(value instance_, value change) {
  CAMLparam2(instance_, change);
  gtk_filter_changed(GObject_val(instance_), Int_val(change));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Filter_get_strictness(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_filter_get_strictness(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_Filter_match(value instance_, value item) {
  CAMLparam2(instance_, item);
  gboolean result = gtk_filter_match(GObject_val(instance_), GObject_val(item));
  CAMLreturn((result ? Val_true : Val_false));
}

void ml_Gtk_Filter_signal_handler_changed(GObject *instance_, int change, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_int(change);
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Filter_signal_connect_changed(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "changed", ml_Gtk_Filter_signal_handler_changed, callback);
}

CAMLprim value ml_Gtk_FilterListModel_get_filter(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_filter_list_model_get_filter(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_FilterListModel_get_incremental(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_filter_list_model_get_incremental(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_FilterListModel_get_pending(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_filter_list_model_get_pending(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_FilterListModel_set_filter(value instance_, value filter) {
  CAMLparam2(instance_, filter);
  gtk_filter_list_model_set_filter(GObject_val(instance_), GObject_val(filter));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_FilterListModel_set_incremental(value instance_, value incremental) {
  CAMLparam2(instance_, incremental);
  gtk_filter_list_model_set_incremental(GObject_val(instance_), Bool_val(incremental));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Fixed_new() {
  CAMLparam0();
  void * result = gtk_fixed_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Fixed_remove(value instance_, value widget) {
  CAMLparam2(instance_, widget);
  gtk_fixed_remove(GObject_val(instance_), GObject_val(widget));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_FixedLayout_new() {
  CAMLparam0();
  void * result = gtk_fixed_layout_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_FlowBox_new() {
  CAMLparam0();
  void * result = gtk_flow_box_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_FlowBox_append(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_flow_box_append(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_FlowBox_get_activate_on_single_click(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_flow_box_get_activate_on_single_click(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_FlowBox_get_child_at_index(value instance_, value idx) {
  CAMLparam2(instance_, idx);
  void * result = gtk_flow_box_get_child_at_index(GObject_val(instance_), Long_val(idx));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_FlowBox_get_child_at_pos(value instance_, value x, value y) {
  CAMLparam3(instance_, x, y);
  void * result = gtk_flow_box_get_child_at_pos(GObject_val(instance_), Long_val(x), Long_val(y));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_FlowBox_get_column_spacing(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_flow_box_get_column_spacing(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_FlowBox_get_homogeneous(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_flow_box_get_homogeneous(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_FlowBox_get_max_children_per_line(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_flow_box_get_max_children_per_line(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_FlowBox_get_min_children_per_line(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_flow_box_get_min_children_per_line(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_FlowBox_get_row_spacing(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_flow_box_get_row_spacing(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_FlowBox_get_selection_mode(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_flow_box_get_selection_mode(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_FlowBox_insert(value instance_, value widget, value position) {
  CAMLparam3(instance_, widget, position);
  gtk_flow_box_insert(GObject_val(instance_), GObject_val(widget), Long_val(position));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_FlowBox_invalidate_filter(value instance_) {
  CAMLparam1(instance_);
  gtk_flow_box_invalidate_filter(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_FlowBox_invalidate_sort(value instance_) {
  CAMLparam1(instance_);
  gtk_flow_box_invalidate_sort(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_FlowBox_prepend(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_flow_box_prepend(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_FlowBox_remove(value instance_, value widget) {
  CAMLparam2(instance_, widget);
  gtk_flow_box_remove(GObject_val(instance_), GObject_val(widget));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_FlowBox_select_all(value instance_) {
  CAMLparam1(instance_);
  gtk_flow_box_select_all(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_FlowBox_select_child(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_flow_box_select_child(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_FlowBox_set_activate_on_single_click(value instance_, value single) {
  CAMLparam2(instance_, single);
  gtk_flow_box_set_activate_on_single_click(GObject_val(instance_), Bool_val(single));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_FlowBox_set_column_spacing(value instance_, value spacing) {
  CAMLparam2(instance_, spacing);
  gtk_flow_box_set_column_spacing(GObject_val(instance_), Long_val(spacing));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_FlowBox_set_hadjustment(value instance_, value adjustment) {
  CAMLparam2(instance_, adjustment);
  gtk_flow_box_set_hadjustment(GObject_val(instance_), GObject_val(adjustment));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_FlowBox_set_homogeneous(value instance_, value homogeneous) {
  CAMLparam2(instance_, homogeneous);
  gtk_flow_box_set_homogeneous(GObject_val(instance_), Bool_val(homogeneous));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_FlowBox_set_max_children_per_line(value instance_, value n_children) {
  CAMLparam2(instance_, n_children);
  gtk_flow_box_set_max_children_per_line(GObject_val(instance_), Long_val(n_children));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_FlowBox_set_min_children_per_line(value instance_, value n_children) {
  CAMLparam2(instance_, n_children);
  gtk_flow_box_set_min_children_per_line(GObject_val(instance_), Long_val(n_children));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_FlowBox_set_row_spacing(value instance_, value spacing) {
  CAMLparam2(instance_, spacing);
  gtk_flow_box_set_row_spacing(GObject_val(instance_), Long_val(spacing));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_FlowBox_set_selection_mode(value instance_, value mode) {
  CAMLparam2(instance_, mode);
  gtk_flow_box_set_selection_mode(GObject_val(instance_), Int_val(mode));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_FlowBox_set_vadjustment(value instance_, value adjustment) {
  CAMLparam2(instance_, adjustment);
  gtk_flow_box_set_vadjustment(GObject_val(instance_), GObject_val(adjustment));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_FlowBox_unselect_all(value instance_) {
  CAMLparam1(instance_);
  gtk_flow_box_unselect_all(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_FlowBox_unselect_child(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_flow_box_unselect_child(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

void ml_Gtk_FlowBox_signal_handler_activate_cursor_child(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_FlowBox_signal_connect_activate_cursor_child(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "activate-cursor-child", ml_Gtk_FlowBox_signal_handler_activate_cursor_child, callback);
}

void ml_Gtk_FlowBox_signal_handler_child_activated(GObject *instance_, void * child, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(child));
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_FlowBox_signal_connect_child_activated(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "child-activated", ml_Gtk_FlowBox_signal_handler_child_activated, callback);
}

gboolean ml_Gtk_FlowBox_signal_handler_move_cursor(GObject *instance_, int step, gint32 count, gboolean extend, gboolean modify, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 4);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_int(step);
  args[1] = Val_long(count);
  args[2] = (extend ? Val_true : Val_false);
  args[3] = (modify ? Val_true : Val_false);
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 4, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_FlowBox_signal_connect_move_cursor(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "move-cursor", ml_Gtk_FlowBox_signal_handler_move_cursor, callback);
}

void ml_Gtk_FlowBox_signal_handler_select_all(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_FlowBox_signal_connect_select_all(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "select-all", ml_Gtk_FlowBox_signal_handler_select_all, callback);
}

void ml_Gtk_FlowBox_signal_handler_selected_children_changed(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_FlowBox_signal_connect_selected_children_changed(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "selected-children-changed", ml_Gtk_FlowBox_signal_handler_selected_children_changed, callback);
}

void ml_Gtk_FlowBox_signal_handler_toggle_cursor_child(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_FlowBox_signal_connect_toggle_cursor_child(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "toggle-cursor-child", ml_Gtk_FlowBox_signal_handler_toggle_cursor_child, callback);
}

void ml_Gtk_FlowBox_signal_handler_unselect_all(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_FlowBox_signal_connect_unselect_all(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "unselect-all", ml_Gtk_FlowBox_signal_handler_unselect_all, callback);
}

CAMLprim value ml_Gtk_FlowBoxChild_new() {
  CAMLparam0();
  void * result = gtk_flow_box_child_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_FlowBoxChild_changed(value instance_) {
  CAMLparam1(instance_);
  gtk_flow_box_child_changed(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_FlowBoxChild_get_child(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_flow_box_child_get_child(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_FlowBoxChild_get_index(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_flow_box_child_get_index(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_FlowBoxChild_is_selected(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_flow_box_child_is_selected(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_FlowBoxChild_set_child(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_flow_box_child_set_child(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

void ml_Gtk_FlowBoxChild_signal_handler_activate(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_FlowBoxChild_signal_connect_activate(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "activate", ml_Gtk_FlowBoxChild_signal_handler_activate, callback);
}

CAMLprim value ml_Gtk_FontButton_new() {
  CAMLparam0();
  void * result = gtk_font_button_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_FontButton_new_with_font(value fontname) {
  CAMLparam1(fontname);
  void * result = gtk_font_button_new_with_font(String_val(fontname));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_FontButton_get_modal(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_font_button_get_modal(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_FontButton_get_use_font(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_font_button_get_use_font(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_FontButton_get_use_size(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_font_button_get_use_size(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_FontButton_set_modal(value instance_, value modal) {
  CAMLparam2(instance_, modal);
  gtk_font_button_set_modal(GObject_val(instance_), Bool_val(modal));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_FontButton_set_title(value instance_, value title) {
  CAMLparam2(instance_, title);
  gtk_font_button_set_title(GObject_val(instance_), String_val(title));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_FontButton_set_use_font(value instance_, value use_font) {
  CAMLparam2(instance_, use_font);
  gtk_font_button_set_use_font(GObject_val(instance_), Bool_val(use_font));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_FontButton_set_use_size(value instance_, value use_size) {
  CAMLparam2(instance_, use_size);
  gtk_font_button_set_use_size(GObject_val(instance_), Bool_val(use_size));
  CAMLreturn(Val_unit);
}

void ml_Gtk_FontButton_signal_handler_activate(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_FontButton_signal_connect_activate(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "activate", ml_Gtk_FontButton_signal_handler_activate, callback);
}

void ml_Gtk_FontButton_signal_handler_font_set(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_FontButton_signal_connect_font_set(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "font-set", ml_Gtk_FontButton_signal_handler_font_set, callback);
}

CAMLprim value ml_Gtk_FontChooserDialog_new(value title, value parent) {
  CAMLparam2(title, parent);
  void * result = gtk_font_chooser_dialog_new(String_val(title), GObject_val(parent));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_FontChooserWidget_new() {
  CAMLparam0();
  void * result = gtk_font_chooser_widget_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Frame_new(value label) {
  CAMLparam1(label);
  void * result = gtk_frame_new(String_val(label));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Frame_get_child(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_frame_get_child(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Frame_get_label_widget(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_frame_get_label_widget(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Frame_set_child(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_frame_set_child(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Frame_set_label(value instance_, value label) {
  CAMLparam2(instance_, label);
  gtk_frame_set_label(GObject_val(instance_), String_val(label));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Frame_set_label_widget(value instance_, value label_widget) {
  CAMLparam2(instance_, label_widget);
  gtk_frame_set_label_widget(GObject_val(instance_), GObject_val(label_widget));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_GLArea_new() {
  CAMLparam0();
  void * result = gtk_gl_area_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_GLArea_attach_buffers(value instance_) {
  CAMLparam1(instance_);
  gtk_gl_area_attach_buffers(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_GLArea_get_auto_render(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_gl_area_get_auto_render(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_GLArea_get_context(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_gl_area_get_context(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_GLArea_get_has_depth_buffer(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_gl_area_get_has_depth_buffer(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_GLArea_get_has_stencil_buffer(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_gl_area_get_has_stencil_buffer(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_GLArea_get_use_es(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_gl_area_get_use_es(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_GLArea_make_current(value instance_) {
  CAMLparam1(instance_);
  gtk_gl_area_make_current(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_GLArea_queue_render(value instance_) {
  CAMLparam1(instance_);
  gtk_gl_area_queue_render(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_GLArea_set_auto_render(value instance_, value auto_render) {
  CAMLparam2(instance_, auto_render);
  gtk_gl_area_set_auto_render(GObject_val(instance_), Bool_val(auto_render));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_GLArea_set_has_depth_buffer(value instance_, value has_depth_buffer) {
  CAMLparam2(instance_, has_depth_buffer);
  gtk_gl_area_set_has_depth_buffer(GObject_val(instance_), Bool_val(has_depth_buffer));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_GLArea_set_has_stencil_buffer(value instance_, value has_stencil_buffer) {
  CAMLparam2(instance_, has_stencil_buffer);
  gtk_gl_area_set_has_stencil_buffer(GObject_val(instance_), Bool_val(has_stencil_buffer));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_GLArea_set_required_version(value instance_, value major, value minor) {
  CAMLparam3(instance_, major, minor);
  gtk_gl_area_set_required_version(GObject_val(instance_), Long_val(major), Long_val(minor));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_GLArea_set_use_es(value instance_, value use_es) {
  CAMLparam2(instance_, use_es);
  gtk_gl_area_set_use_es(GObject_val(instance_), Bool_val(use_es));
  CAMLreturn(Val_unit);
}

void * ml_Gtk_GLArea_signal_handler_create_context(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  void * result = GObject_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(void *, result);
}

CAMLprim value ml_Gtk_GLArea_signal_connect_create_context(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "create-context", ml_Gtk_GLArea_signal_handler_create_context, callback);
}

gboolean ml_Gtk_GLArea_signal_handler_render(GObject *instance_, void * context, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(context));
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_GLArea_signal_connect_render(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "render", ml_Gtk_GLArea_signal_handler_render, callback);
}

void ml_Gtk_GLArea_signal_handler_resize(GObject *instance_, gint32 width, gint32 height, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 2);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_long(width);
  args[1] = Val_long(height);
  ;caml_callbackN(*callbackCell, 2, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_GLArea_signal_connect_resize(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "resize", ml_Gtk_GLArea_signal_handler_resize, callback);
}

CAMLprim value ml_Gtk_Gesture_get_device(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_gesture_get_device(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Gesture_group(value instance_, value gesture) {
  CAMLparam2(instance_, gesture);
  gtk_gesture_group(GObject_val(instance_), GObject_val(gesture));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Gesture_is_active(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_gesture_is_active(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Gesture_is_grouped_with(value instance_, value other) {
  CAMLparam2(instance_, other);
  gboolean result = gtk_gesture_is_grouped_with(GObject_val(instance_), GObject_val(other));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Gesture_is_recognized(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_gesture_is_recognized(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Gesture_set_state(value instance_, value state) {
  CAMLparam2(instance_, state);
  gboolean result = gtk_gesture_set_state(GObject_val(instance_), Int_val(state));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Gesture_ungroup(value instance_) {
  CAMLparam1(instance_);
  gtk_gesture_ungroup(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_GestureClick_new() {
  CAMLparam0();
  void * result = gtk_gesture_click_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

void ml_Gtk_GestureClick_signal_handler_stopped(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_GestureClick_signal_connect_stopped(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "stopped", ml_Gtk_GestureClick_signal_handler_stopped, callback);
}

CAMLprim value ml_Gtk_GestureDrag_new() {
  CAMLparam0();
  void * result = gtk_gesture_drag_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_GestureLongPress_new() {
  CAMLparam0();
  void * result = gtk_gesture_long_press_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

void ml_Gtk_GestureLongPress_signal_handler_cancelled(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_GestureLongPress_signal_connect_cancelled(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "cancelled", ml_Gtk_GestureLongPress_signal_handler_cancelled, callback);
}

CAMLprim value ml_Gtk_GesturePan_new(value orientation) {
  CAMLparam1(orientation);
  void * result = gtk_gesture_pan_new(Int_val(orientation));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_GesturePan_get_orientation(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_gesture_pan_get_orientation(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_GesturePan_set_orientation(value instance_, value orientation) {
  CAMLparam2(instance_, orientation);
  gtk_gesture_pan_set_orientation(GObject_val(instance_), Int_val(orientation));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_GestureRotate_new() {
  CAMLparam0();
  void * result = gtk_gesture_rotate_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_GestureSingle_get_button(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_gesture_single_get_button(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_GestureSingle_get_current_button(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_gesture_single_get_current_button(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_GestureSingle_get_exclusive(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_gesture_single_get_exclusive(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_GestureSingle_get_touch_only(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_gesture_single_get_touch_only(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_GestureSingle_set_button(value instance_, value button) {
  CAMLparam2(instance_, button);
  gtk_gesture_single_set_button(GObject_val(instance_), Long_val(button));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_GestureSingle_set_exclusive(value instance_, value exclusive) {
  CAMLparam2(instance_, exclusive);
  gtk_gesture_single_set_exclusive(GObject_val(instance_), Bool_val(exclusive));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_GestureSingle_set_touch_only(value instance_, value touch_only) {
  CAMLparam2(instance_, touch_only);
  gtk_gesture_single_set_touch_only(GObject_val(instance_), Bool_val(touch_only));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_GestureStylus_new() {
  CAMLparam0();
  void * result = gtk_gesture_stylus_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_GestureStylus_get_device_tool(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_gesture_stylus_get_device_tool(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_GestureSwipe_new() {
  CAMLparam0();
  void * result = gtk_gesture_swipe_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_GestureZoom_new() {
  CAMLparam0();
  void * result = gtk_gesture_zoom_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Grid_new() {
  CAMLparam0();
  void * result = gtk_grid_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Grid_get_baseline_row(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_grid_get_baseline_row(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Grid_get_child_at(value instance_, value column, value row) {
  CAMLparam3(instance_, column, row);
  void * result = gtk_grid_get_child_at(GObject_val(instance_), Long_val(column), Long_val(row));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Grid_get_column_homogeneous(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_grid_get_column_homogeneous(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Grid_get_column_spacing(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_grid_get_column_spacing(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Grid_get_row_baseline_position(value instance_, value row) {
  CAMLparam2(instance_, row);
  int result = gtk_grid_get_row_baseline_position(GObject_val(instance_), Long_val(row));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_Grid_get_row_homogeneous(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_grid_get_row_homogeneous(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Grid_get_row_spacing(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_grid_get_row_spacing(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Grid_insert_column(value instance_, value position) {
  CAMLparam2(instance_, position);
  gtk_grid_insert_column(GObject_val(instance_), Long_val(position));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Grid_insert_next_to(value instance_, value sibling, value side) {
  CAMLparam3(instance_, sibling, side);
  gtk_grid_insert_next_to(GObject_val(instance_), GObject_val(sibling), Int_val(side));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Grid_insert_row(value instance_, value position) {
  CAMLparam2(instance_, position);
  gtk_grid_insert_row(GObject_val(instance_), Long_val(position));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Grid_remove(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_grid_remove(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Grid_remove_column(value instance_, value position) {
  CAMLparam2(instance_, position);
  gtk_grid_remove_column(GObject_val(instance_), Long_val(position));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Grid_remove_row(value instance_, value position) {
  CAMLparam2(instance_, position);
  gtk_grid_remove_row(GObject_val(instance_), Long_val(position));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Grid_set_baseline_row(value instance_, value row) {
  CAMLparam2(instance_, row);
  gtk_grid_set_baseline_row(GObject_val(instance_), Long_val(row));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Grid_set_column_homogeneous(value instance_, value homogeneous) {
  CAMLparam2(instance_, homogeneous);
  gtk_grid_set_column_homogeneous(GObject_val(instance_), Bool_val(homogeneous));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Grid_set_column_spacing(value instance_, value spacing) {
  CAMLparam2(instance_, spacing);
  gtk_grid_set_column_spacing(GObject_val(instance_), Long_val(spacing));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Grid_set_row_baseline_position(value instance_, value row, value pos) {
  CAMLparam3(instance_, row, pos);
  gtk_grid_set_row_baseline_position(GObject_val(instance_), Long_val(row), Int_val(pos));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Grid_set_row_homogeneous(value instance_, value homogeneous) {
  CAMLparam2(instance_, homogeneous);
  gtk_grid_set_row_homogeneous(GObject_val(instance_), Bool_val(homogeneous));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Grid_set_row_spacing(value instance_, value spacing) {
  CAMLparam2(instance_, spacing);
  gtk_grid_set_row_spacing(GObject_val(instance_), Long_val(spacing));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_GridLayout_new() {
  CAMLparam0();
  void * result = gtk_grid_layout_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_GridLayout_get_baseline_row(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_grid_layout_get_baseline_row(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_GridLayout_get_column_homogeneous(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_grid_layout_get_column_homogeneous(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_GridLayout_get_column_spacing(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_grid_layout_get_column_spacing(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_GridLayout_get_row_baseline_position(value instance_, value row) {
  CAMLparam2(instance_, row);
  int result = gtk_grid_layout_get_row_baseline_position(GObject_val(instance_), Long_val(row));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_GridLayout_get_row_homogeneous(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_grid_layout_get_row_homogeneous(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_GridLayout_get_row_spacing(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_grid_layout_get_row_spacing(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_GridLayout_set_baseline_row(value instance_, value row) {
  CAMLparam2(instance_, row);
  gtk_grid_layout_set_baseline_row(GObject_val(instance_), Long_val(row));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_GridLayout_set_column_homogeneous(value instance_, value homogeneous) {
  CAMLparam2(instance_, homogeneous);
  gtk_grid_layout_set_column_homogeneous(GObject_val(instance_), Bool_val(homogeneous));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_GridLayout_set_column_spacing(value instance_, value spacing) {
  CAMLparam2(instance_, spacing);
  gtk_grid_layout_set_column_spacing(GObject_val(instance_), Long_val(spacing));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_GridLayout_set_row_baseline_position(value instance_, value row, value pos) {
  CAMLparam3(instance_, row, pos);
  gtk_grid_layout_set_row_baseline_position(GObject_val(instance_), Long_val(row), Int_val(pos));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_GridLayout_set_row_homogeneous(value instance_, value homogeneous) {
  CAMLparam2(instance_, homogeneous);
  gtk_grid_layout_set_row_homogeneous(GObject_val(instance_), Bool_val(homogeneous));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_GridLayout_set_row_spacing(value instance_, value spacing) {
  CAMLparam2(instance_, spacing);
  gtk_grid_layout_set_row_spacing(GObject_val(instance_), Long_val(spacing));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_GridLayoutChild_get_column(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_grid_layout_child_get_column(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_GridLayoutChild_get_column_span(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_grid_layout_child_get_column_span(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_GridLayoutChild_get_row(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_grid_layout_child_get_row(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_GridLayoutChild_get_row_span(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_grid_layout_child_get_row_span(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_GridLayoutChild_set_column(value instance_, value column) {
  CAMLparam2(instance_, column);
  gtk_grid_layout_child_set_column(GObject_val(instance_), Long_val(column));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_GridLayoutChild_set_column_span(value instance_, value span) {
  CAMLparam2(instance_, span);
  gtk_grid_layout_child_set_column_span(GObject_val(instance_), Long_val(span));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_GridLayoutChild_set_row(value instance_, value row) {
  CAMLparam2(instance_, row);
  gtk_grid_layout_child_set_row(GObject_val(instance_), Long_val(row));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_GridLayoutChild_set_row_span(value instance_, value span) {
  CAMLparam2(instance_, span);
  gtk_grid_layout_child_set_row_span(GObject_val(instance_), Long_val(span));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_GridView_get_enable_rubberband(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_grid_view_get_enable_rubberband(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_GridView_get_factory(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_grid_view_get_factory(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_GridView_get_max_columns(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_grid_view_get_max_columns(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_GridView_get_min_columns(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_grid_view_get_min_columns(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_GridView_get_single_click_activate(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_grid_view_get_single_click_activate(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_GridView_set_enable_rubberband(value instance_, value enable_rubberband) {
  CAMLparam2(instance_, enable_rubberband);
  gtk_grid_view_set_enable_rubberband(GObject_val(instance_), Bool_val(enable_rubberband));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_GridView_set_factory(value instance_, value factory) {
  CAMLparam2(instance_, factory);
  gtk_grid_view_set_factory(GObject_val(instance_), GObject_val(factory));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_GridView_set_max_columns(value instance_, value max_columns) {
  CAMLparam2(instance_, max_columns);
  gtk_grid_view_set_max_columns(GObject_val(instance_), Long_val(max_columns));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_GridView_set_min_columns(value instance_, value min_columns) {
  CAMLparam2(instance_, min_columns);
  gtk_grid_view_set_min_columns(GObject_val(instance_), Long_val(min_columns));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_GridView_set_single_click_activate(value instance_, value single_click_activate) {
  CAMLparam2(instance_, single_click_activate);
  gtk_grid_view_set_single_click_activate(GObject_val(instance_), Bool_val(single_click_activate));
  CAMLreturn(Val_unit);
}

void ml_Gtk_GridView_signal_handler_activate(GObject *instance_, guint32 position, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_long(position);
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_GridView_signal_connect_activate(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "activate", ml_Gtk_GridView_signal_handler_activate, callback);
}

CAMLprim value ml_Gtk_HeaderBar_new() {
  CAMLparam0();
  void * result = gtk_header_bar_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_HeaderBar_get_show_title_buttons(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_header_bar_get_show_title_buttons(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_HeaderBar_get_title_widget(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_header_bar_get_title_widget(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_HeaderBar_pack_end(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_header_bar_pack_end(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_HeaderBar_pack_start(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_header_bar_pack_start(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_HeaderBar_remove(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_header_bar_remove(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_HeaderBar_set_decoration_layout(value instance_, value layout) {
  CAMLparam2(instance_, layout);
  gtk_header_bar_set_decoration_layout(GObject_val(instance_), String_val(layout));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_HeaderBar_set_show_title_buttons(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_header_bar_set_show_title_buttons(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_HeaderBar_set_title_widget(value instance_, value title_widget) {
  CAMLparam2(instance_, title_widget);
  gtk_header_bar_set_title_widget(GObject_val(instance_), GObject_val(title_widget));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_IMContext_delete_surrounding(value instance_, value offset, value n_chars) {
  CAMLparam3(instance_, offset, n_chars);
  gboolean result = gtk_im_context_delete_surrounding(GObject_val(instance_), Long_val(offset), Long_val(n_chars));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_IMContext_focus_in(value instance_) {
  CAMLparam1(instance_);
  gtk_im_context_focus_in(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_IMContext_focus_out(value instance_) {
  CAMLparam1(instance_);
  gtk_im_context_focus_out(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_IMContext_reset(value instance_) {
  CAMLparam1(instance_);
  gtk_im_context_reset(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_IMContext_set_client_widget(value instance_, value widget) {
  CAMLparam2(instance_, widget);
  gtk_im_context_set_client_widget(GObject_val(instance_), GObject_val(widget));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_IMContext_set_surrounding(value instance_, value text, value len, value cursor_index) {
  CAMLparam4(instance_, text, len, cursor_index);
  gtk_im_context_set_surrounding(GObject_val(instance_), String_val(text), Long_val(len), Long_val(cursor_index));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_IMContext_set_surrounding_with_selection(value instance_, value text, value len, value cursor_index, value anchor_index) {
  CAMLparam5(instance_, text, len, cursor_index, anchor_index);
  gtk_im_context_set_surrounding_with_selection(GObject_val(instance_), String_val(text), Long_val(len), Long_val(cursor_index), Long_val(anchor_index));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_IMContext_set_use_preedit(value instance_, value use_preedit) {
  CAMLparam2(instance_, use_preedit);
  gtk_im_context_set_use_preedit(GObject_val(instance_), Bool_val(use_preedit));
  CAMLreturn(Val_unit);
}

gboolean ml_Gtk_IMContext_signal_handler_delete_surrounding(GObject *instance_, gint32 offset, gint32 n_chars, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 2);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_long(offset);
  args[1] = Val_long(n_chars);
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 2, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_IMContext_signal_connect_delete_surrounding(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "delete-surrounding", ml_Gtk_IMContext_signal_handler_delete_surrounding, callback);
}

void ml_Gtk_IMContext_signal_handler_preedit_changed(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_IMContext_signal_connect_preedit_changed(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "preedit-changed", ml_Gtk_IMContext_signal_handler_preedit_changed, callback);
}

void ml_Gtk_IMContext_signal_handler_preedit_end(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_IMContext_signal_connect_preedit_end(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "preedit-end", ml_Gtk_IMContext_signal_handler_preedit_end, callback);
}

void ml_Gtk_IMContext_signal_handler_preedit_start(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_IMContext_signal_connect_preedit_start(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "preedit-start", ml_Gtk_IMContext_signal_handler_preedit_start, callback);
}

gboolean ml_Gtk_IMContext_signal_handler_retrieve_surrounding(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_IMContext_signal_connect_retrieve_surrounding(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "retrieve-surrounding", ml_Gtk_IMContext_signal_handler_retrieve_surrounding, callback);
}

CAMLprim value ml_Gtk_IMContextSimple_new() {
  CAMLparam0();
  void * result = gtk_im_context_simple_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_IMContextSimple_add_compose_file(value instance_, value compose_file) {
  CAMLparam2(instance_, compose_file);
  gtk_im_context_simple_add_compose_file(GObject_val(instance_), String_val(compose_file));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_IMMulticontext_new() {
  CAMLparam0();
  void * result = gtk_im_multicontext_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_IMMulticontext_set_context_id(value instance_, value context_id) {
  CAMLparam2(instance_, context_id);
  gtk_im_multicontext_set_context_id(GObject_val(instance_), String_val(context_id));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_IconPaintable_is_symbolic(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_icon_paintable_is_symbolic(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_IconTheme_new() {
  CAMLparam0();
  void * result = gtk_icon_theme_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_IconTheme_add_resource_path(value instance_, value path) {
  CAMLparam2(instance_, path);
  gtk_icon_theme_add_resource_path(GObject_val(instance_), String_val(path));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_IconTheme_get_display(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_icon_theme_get_display(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_IconTheme_has_icon(value instance_, value icon_name) {
  CAMLparam2(instance_, icon_name);
  gboolean result = gtk_icon_theme_has_icon(GObject_val(instance_), String_val(icon_name));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_IconTheme_set_theme_name(value instance_, value theme_name) {
  CAMLparam2(instance_, theme_name);
  gtk_icon_theme_set_theme_name(GObject_val(instance_), String_val(theme_name));
  CAMLreturn(Val_unit);
}

void ml_Gtk_IconTheme_signal_handler_changed(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_IconTheme_signal_connect_changed(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "changed", ml_Gtk_IconTheme_signal_handler_changed, callback);
}

CAMLprim value ml_Gtk_IconView_new() {
  CAMLparam0();
  void * result = gtk_icon_view_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_IconView_new_with_area(value area) {
  CAMLparam1(area);
  void * result = gtk_icon_view_new_with_area(GObject_val(area));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_IconView_get_activate_on_single_click(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_icon_view_get_activate_on_single_click(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_IconView_get_column_spacing(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_icon_view_get_column_spacing(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_IconView_get_columns(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_icon_view_get_columns(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_IconView_get_item_orientation(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_icon_view_get_item_orientation(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_IconView_get_item_padding(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_icon_view_get_item_padding(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_IconView_get_item_width(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_icon_view_get_item_width(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_IconView_get_margin(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_icon_view_get_margin(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_IconView_get_markup_column(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_icon_view_get_markup_column(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_IconView_get_pixbuf_column(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_icon_view_get_pixbuf_column(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_IconView_get_reorderable(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_icon_view_get_reorderable(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_IconView_get_row_spacing(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_icon_view_get_row_spacing(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_IconView_get_selection_mode(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_icon_view_get_selection_mode(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_IconView_get_spacing(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_icon_view_get_spacing(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_IconView_get_text_column(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_icon_view_get_text_column(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_IconView_get_tooltip_column(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_icon_view_get_tooltip_column(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_IconView_select_all(value instance_) {
  CAMLparam1(instance_);
  gtk_icon_view_select_all(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_IconView_set_activate_on_single_click(value instance_, value single) {
  CAMLparam2(instance_, single);
  gtk_icon_view_set_activate_on_single_click(GObject_val(instance_), Bool_val(single));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_IconView_set_column_spacing(value instance_, value column_spacing) {
  CAMLparam2(instance_, column_spacing);
  gtk_icon_view_set_column_spacing(GObject_val(instance_), Long_val(column_spacing));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_IconView_set_columns(value instance_, value columns) {
  CAMLparam2(instance_, columns);
  gtk_icon_view_set_columns(GObject_val(instance_), Long_val(columns));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_IconView_set_item_orientation(value instance_, value orientation) {
  CAMLparam2(instance_, orientation);
  gtk_icon_view_set_item_orientation(GObject_val(instance_), Int_val(orientation));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_IconView_set_item_padding(value instance_, value item_padding) {
  CAMLparam2(instance_, item_padding);
  gtk_icon_view_set_item_padding(GObject_val(instance_), Long_val(item_padding));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_IconView_set_item_width(value instance_, value item_width) {
  CAMLparam2(instance_, item_width);
  gtk_icon_view_set_item_width(GObject_val(instance_), Long_val(item_width));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_IconView_set_margin(value instance_, value margin) {
  CAMLparam2(instance_, margin);
  gtk_icon_view_set_margin(GObject_val(instance_), Long_val(margin));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_IconView_set_markup_column(value instance_, value column) {
  CAMLparam2(instance_, column);
  gtk_icon_view_set_markup_column(GObject_val(instance_), Long_val(column));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_IconView_set_pixbuf_column(value instance_, value column) {
  CAMLparam2(instance_, column);
  gtk_icon_view_set_pixbuf_column(GObject_val(instance_), Long_val(column));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_IconView_set_reorderable(value instance_, value reorderable) {
  CAMLparam2(instance_, reorderable);
  gtk_icon_view_set_reorderable(GObject_val(instance_), Bool_val(reorderable));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_IconView_set_row_spacing(value instance_, value row_spacing) {
  CAMLparam2(instance_, row_spacing);
  gtk_icon_view_set_row_spacing(GObject_val(instance_), Long_val(row_spacing));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_IconView_set_selection_mode(value instance_, value mode) {
  CAMLparam2(instance_, mode);
  gtk_icon_view_set_selection_mode(GObject_val(instance_), Int_val(mode));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_IconView_set_spacing(value instance_, value spacing) {
  CAMLparam2(instance_, spacing);
  gtk_icon_view_set_spacing(GObject_val(instance_), Long_val(spacing));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_IconView_set_text_column(value instance_, value column) {
  CAMLparam2(instance_, column);
  gtk_icon_view_set_text_column(GObject_val(instance_), Long_val(column));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_IconView_set_tooltip_column(value instance_, value column) {
  CAMLparam2(instance_, column);
  gtk_icon_view_set_tooltip_column(GObject_val(instance_), Long_val(column));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_IconView_unselect_all(value instance_) {
  CAMLparam1(instance_);
  gtk_icon_view_unselect_all(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_IconView_unset_model_drag_dest(value instance_) {
  CAMLparam1(instance_);
  gtk_icon_view_unset_model_drag_dest(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_IconView_unset_model_drag_source(value instance_) {
  CAMLparam1(instance_);
  gtk_icon_view_unset_model_drag_source(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

gboolean ml_Gtk_IconView_signal_handler_activate_cursor_item(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_IconView_signal_connect_activate_cursor_item(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "activate-cursor-item", ml_Gtk_IconView_signal_handler_activate_cursor_item, callback);
}

gboolean ml_Gtk_IconView_signal_handler_move_cursor(GObject *instance_, int step, gint32 count, gboolean extend, gboolean modify, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 4);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_int(step);
  args[1] = Val_long(count);
  args[2] = (extend ? Val_true : Val_false);
  args[3] = (modify ? Val_true : Val_false);
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 4, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_IconView_signal_connect_move_cursor(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "move-cursor", ml_Gtk_IconView_signal_handler_move_cursor, callback);
}

void ml_Gtk_IconView_signal_handler_select_all(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_IconView_signal_connect_select_all(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "select-all", ml_Gtk_IconView_signal_handler_select_all, callback);
}

void ml_Gtk_IconView_signal_handler_select_cursor_item(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_IconView_signal_connect_select_cursor_item(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "select-cursor-item", ml_Gtk_IconView_signal_handler_select_cursor_item, callback);
}

void ml_Gtk_IconView_signal_handler_selection_changed(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_IconView_signal_connect_selection_changed(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "selection-changed", ml_Gtk_IconView_signal_handler_selection_changed, callback);
}

void ml_Gtk_IconView_signal_handler_toggle_cursor_item(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_IconView_signal_connect_toggle_cursor_item(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "toggle-cursor-item", ml_Gtk_IconView_signal_handler_toggle_cursor_item, callback);
}

void ml_Gtk_IconView_signal_handler_unselect_all(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_IconView_signal_connect_unselect_all(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "unselect-all", ml_Gtk_IconView_signal_handler_unselect_all, callback);
}

CAMLprim value ml_Gtk_Image_new() {
  CAMLparam0();
  void * result = gtk_image_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Image_new_from_icon_name(value icon_name) {
  CAMLparam1(icon_name);
  void * result = gtk_image_new_from_icon_name(String_val(icon_name));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Image_new_from_resource(value resource_path) {
  CAMLparam1(resource_path);
  void * result = gtk_image_new_from_resource(String_val(resource_path));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Image_clear(value instance_) {
  CAMLparam1(instance_);
  gtk_image_clear(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Image_get_icon_size(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_image_get_icon_size(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_Image_get_pixel_size(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_image_get_pixel_size(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Image_get_storage_type(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_image_get_storage_type(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_Image_set_from_icon_name(value instance_, value icon_name) {
  CAMLparam2(instance_, icon_name);
  gtk_image_set_from_icon_name(GObject_val(instance_), String_val(icon_name));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Image_set_from_resource(value instance_, value resource_path) {
  CAMLparam2(instance_, resource_path);
  gtk_image_set_from_resource(GObject_val(instance_), String_val(resource_path));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Image_set_icon_size(value instance_, value icon_size) {
  CAMLparam2(instance_, icon_size);
  gtk_image_set_icon_size(GObject_val(instance_), Int_val(icon_size));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Image_set_pixel_size(value instance_, value pixel_size) {
  CAMLparam2(instance_, pixel_size);
  gtk_image_set_pixel_size(GObject_val(instance_), Long_val(pixel_size));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_InfoBar_new() {
  CAMLparam0();
  void * result = gtk_info_bar_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_InfoBar_add_action_widget(value instance_, value child, value response_id) {
  CAMLparam3(instance_, child, response_id);
  gtk_info_bar_add_action_widget(GObject_val(instance_), GObject_val(child), Long_val(response_id));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_InfoBar_add_button(value instance_, value button_text, value response_id) {
  CAMLparam3(instance_, button_text, response_id);
  void * result = gtk_info_bar_add_button(GObject_val(instance_), String_val(button_text), Long_val(response_id));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_InfoBar_add_child(value instance_, value widget) {
  CAMLparam2(instance_, widget);
  gtk_info_bar_add_child(GObject_val(instance_), GObject_val(widget));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_InfoBar_get_message_type(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_info_bar_get_message_type(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_InfoBar_get_revealed(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_info_bar_get_revealed(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_InfoBar_get_show_close_button(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_info_bar_get_show_close_button(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_InfoBar_remove_action_widget(value instance_, value widget) {
  CAMLparam2(instance_, widget);
  gtk_info_bar_remove_action_widget(GObject_val(instance_), GObject_val(widget));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_InfoBar_remove_child(value instance_, value widget) {
  CAMLparam2(instance_, widget);
  gtk_info_bar_remove_child(GObject_val(instance_), GObject_val(widget));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_InfoBar_response(value instance_, value response_id) {
  CAMLparam2(instance_, response_id);
  gtk_info_bar_response(GObject_val(instance_), Long_val(response_id));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_InfoBar_set_default_response(value instance_, value response_id) {
  CAMLparam2(instance_, response_id);
  gtk_info_bar_set_default_response(GObject_val(instance_), Long_val(response_id));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_InfoBar_set_message_type(value instance_, value message_type) {
  CAMLparam2(instance_, message_type);
  gtk_info_bar_set_message_type(GObject_val(instance_), Int_val(message_type));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_InfoBar_set_response_sensitive(value instance_, value response_id, value setting) {
  CAMLparam3(instance_, response_id, setting);
  gtk_info_bar_set_response_sensitive(GObject_val(instance_), Long_val(response_id), Bool_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_InfoBar_set_revealed(value instance_, value revealed) {
  CAMLparam2(instance_, revealed);
  gtk_info_bar_set_revealed(GObject_val(instance_), Bool_val(revealed));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_InfoBar_set_show_close_button(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_info_bar_set_show_close_button(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

void ml_Gtk_InfoBar_signal_handler_close(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_InfoBar_signal_connect_close(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "close", ml_Gtk_InfoBar_signal_handler_close, callback);
}

void ml_Gtk_InfoBar_signal_handler_response(GObject *instance_, gint32 response_id, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_long(response_id);
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_InfoBar_signal_connect_response(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "response", ml_Gtk_InfoBar_signal_handler_response, callback);
}

CAMLprim value ml_Gtk_KeyvalTrigger_new(value keyval, value modifiers) {
  CAMLparam2(keyval, modifiers);
  void * result = gtk_keyval_trigger_new(Long_val(keyval), Int_val(modifiers));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_KeyvalTrigger_get_keyval(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_keyval_trigger_get_keyval(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Label_new(value str) {
  CAMLparam1(str);
  void * result = gtk_label_new(String_val(str));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Label_new_with_mnemonic(value str) {
  CAMLparam1(str);
  void * result = gtk_label_new_with_mnemonic(String_val(str));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Label_get_extra_menu(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_label_get_extra_menu(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Label_get_justify(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_label_get_justify(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_Label_get_lines(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_label_get_lines(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Label_get_max_width_chars(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_label_get_max_width_chars(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Label_get_mnemonic_keyval(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_label_get_mnemonic_keyval(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Label_get_mnemonic_widget(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_label_get_mnemonic_widget(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Label_get_natural_wrap_mode(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_label_get_natural_wrap_mode(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_Label_get_selectable(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_label_get_selectable(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Label_get_single_line_mode(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_label_get_single_line_mode(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Label_get_use_markup(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_label_get_use_markup(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Label_get_use_underline(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_label_get_use_underline(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Label_get_width_chars(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_label_get_width_chars(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Label_get_wrap(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_label_get_wrap(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Label_select_region(value instance_, value start_offset, value end_offset) {
  CAMLparam3(instance_, start_offset, end_offset);
  gtk_label_select_region(GObject_val(instance_), Long_val(start_offset), Long_val(end_offset));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Label_set_extra_menu(value instance_, value model) {
  CAMLparam2(instance_, model);
  gtk_label_set_extra_menu(GObject_val(instance_), GObject_val(model));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Label_set_justify(value instance_, value jtype) {
  CAMLparam2(instance_, jtype);
  gtk_label_set_justify(GObject_val(instance_), Int_val(jtype));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Label_set_label(value instance_, value str) {
  CAMLparam2(instance_, str);
  gtk_label_set_label(GObject_val(instance_), String_val(str));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Label_set_lines(value instance_, value lines) {
  CAMLparam2(instance_, lines);
  gtk_label_set_lines(GObject_val(instance_), Long_val(lines));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Label_set_markup(value instance_, value str) {
  CAMLparam2(instance_, str);
  gtk_label_set_markup(GObject_val(instance_), String_val(str));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Label_set_markup_with_mnemonic(value instance_, value str) {
  CAMLparam2(instance_, str);
  gtk_label_set_markup_with_mnemonic(GObject_val(instance_), String_val(str));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Label_set_max_width_chars(value instance_, value n_chars) {
  CAMLparam2(instance_, n_chars);
  gtk_label_set_max_width_chars(GObject_val(instance_), Long_val(n_chars));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Label_set_mnemonic_widget(value instance_, value widget) {
  CAMLparam2(instance_, widget);
  gtk_label_set_mnemonic_widget(GObject_val(instance_), GObject_val(widget));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Label_set_natural_wrap_mode(value instance_, value wrap_mode) {
  CAMLparam2(instance_, wrap_mode);
  gtk_label_set_natural_wrap_mode(GObject_val(instance_), Int_val(wrap_mode));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Label_set_selectable(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_label_set_selectable(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Label_set_single_line_mode(value instance_, value single_line_mode) {
  CAMLparam2(instance_, single_line_mode);
  gtk_label_set_single_line_mode(GObject_val(instance_), Bool_val(single_line_mode));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Label_set_text(value instance_, value str) {
  CAMLparam2(instance_, str);
  gtk_label_set_text(GObject_val(instance_), String_val(str));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Label_set_text_with_mnemonic(value instance_, value str) {
  CAMLparam2(instance_, str);
  gtk_label_set_text_with_mnemonic(GObject_val(instance_), String_val(str));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Label_set_use_markup(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_label_set_use_markup(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Label_set_use_underline(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_label_set_use_underline(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Label_set_width_chars(value instance_, value n_chars) {
  CAMLparam2(instance_, n_chars);
  gtk_label_set_width_chars(GObject_val(instance_), Long_val(n_chars));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Label_set_wrap(value instance_, value wrap) {
  CAMLparam2(instance_, wrap);
  gtk_label_set_wrap(GObject_val(instance_), Bool_val(wrap));
  CAMLreturn(Val_unit);
}

void ml_Gtk_Label_signal_handler_activate_current_link(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Label_signal_connect_activate_current_link(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "activate-current-link", ml_Gtk_Label_signal_handler_activate_current_link, callback);
}

void ml_Gtk_Label_signal_handler_copy_clipboard(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Label_signal_connect_copy_clipboard(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "copy-clipboard", ml_Gtk_Label_signal_handler_copy_clipboard, callback);
}

void ml_Gtk_Label_signal_handler_move_cursor(GObject *instance_, int step, gint32 count, gboolean extend_selection, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 3);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_int(step);
  args[1] = Val_long(count);
  args[2] = (extend_selection ? Val_true : Val_false);
  ;caml_callbackN(*callbackCell, 3, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Label_signal_connect_move_cursor(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "move-cursor", ml_Gtk_Label_signal_handler_move_cursor, callback);
}

CAMLprim value ml_Gtk_LayoutChild_get_child_widget(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_layout_child_get_child_widget(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_LayoutChild_get_layout_manager(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_layout_child_get_layout_manager(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_LayoutManager_allocate(value instance_, value widget, value width, value height, value baseline) {
  CAMLparam5(instance_, widget, width, height, baseline);
  gtk_layout_manager_allocate(GObject_val(instance_), GObject_val(widget), Long_val(width), Long_val(height), Long_val(baseline));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_LayoutManager_get_layout_child(value instance_, value child) {
  CAMLparam2(instance_, child);
  void * result = gtk_layout_manager_get_layout_child(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_LayoutManager_get_request_mode(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_layout_manager_get_request_mode(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_LayoutManager_get_widget(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_layout_manager_get_widget(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_LayoutManager_layout_changed(value instance_) {
  CAMLparam1(instance_);
  gtk_layout_manager_layout_changed(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_LevelBar_new() {
  CAMLparam0();
  void * result = gtk_level_bar_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_LevelBar_get_inverted(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_level_bar_get_inverted(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_LevelBar_get_mode(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_level_bar_get_mode(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_LevelBar_remove_offset_value(value instance_, value name) {
  CAMLparam2(instance_, name);
  gtk_level_bar_remove_offset_value(GObject_val(instance_), String_val(name));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_LevelBar_set_inverted(value instance_, value inverted) {
  CAMLparam2(instance_, inverted);
  gtk_level_bar_set_inverted(GObject_val(instance_), Bool_val(inverted));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_LevelBar_set_mode(value instance_, value mode) {
  CAMLparam2(instance_, mode);
  gtk_level_bar_set_mode(GObject_val(instance_), Int_val(mode));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_LinkButton_new(value uri) {
  CAMLparam1(uri);
  void * result = gtk_link_button_new(String_val(uri));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_LinkButton_new_with_label(value uri, value label) {
  CAMLparam2(uri, label);
  void * result = gtk_link_button_new_with_label(String_val(uri), String_val(label));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_LinkButton_get_visited(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_link_button_get_visited(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_LinkButton_set_uri(value instance_, value uri) {
  CAMLparam2(instance_, uri);
  gtk_link_button_set_uri(GObject_val(instance_), String_val(uri));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_LinkButton_set_visited(value instance_, value visited) {
  CAMLparam2(instance_, visited);
  gtk_link_button_set_visited(GObject_val(instance_), Bool_val(visited));
  CAMLreturn(Val_unit);
}

gboolean ml_Gtk_LinkButton_signal_handler_activate_link(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_LinkButton_signal_connect_activate_link(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "activate-link", ml_Gtk_LinkButton_signal_handler_activate_link, callback);
}

CAMLprim value ml_Gtk_ListBox_new() {
  CAMLparam0();
  void * result = gtk_list_box_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ListBox_append(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_list_box_append(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ListBox_drag_highlight_row(value instance_, value row) {
  CAMLparam2(instance_, row);
  gtk_list_box_drag_highlight_row(GObject_val(instance_), GObject_val(row));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ListBox_drag_unhighlight_row(value instance_) {
  CAMLparam1(instance_);
  gtk_list_box_drag_unhighlight_row(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ListBox_get_activate_on_single_click(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_list_box_get_activate_on_single_click(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ListBox_get_adjustment(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_list_box_get_adjustment(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ListBox_get_row_at_index(value instance_, value index_) {
  CAMLparam2(instance_, index_);
  void * result = gtk_list_box_get_row_at_index(GObject_val(instance_), Long_val(index_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ListBox_get_row_at_y(value instance_, value y) {
  CAMLparam2(instance_, y);
  void * result = gtk_list_box_get_row_at_y(GObject_val(instance_), Long_val(y));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ListBox_get_selected_row(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_list_box_get_selected_row(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ListBox_get_selection_mode(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_list_box_get_selection_mode(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_ListBox_get_show_separators(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_list_box_get_show_separators(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ListBox_insert(value instance_, value child, value position) {
  CAMLparam3(instance_, child, position);
  gtk_list_box_insert(GObject_val(instance_), GObject_val(child), Long_val(position));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ListBox_invalidate_filter(value instance_) {
  CAMLparam1(instance_);
  gtk_list_box_invalidate_filter(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ListBox_invalidate_headers(value instance_) {
  CAMLparam1(instance_);
  gtk_list_box_invalidate_headers(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ListBox_invalidate_sort(value instance_) {
  CAMLparam1(instance_);
  gtk_list_box_invalidate_sort(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ListBox_prepend(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_list_box_prepend(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ListBox_remove(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_list_box_remove(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ListBox_select_all(value instance_) {
  CAMLparam1(instance_);
  gtk_list_box_select_all(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ListBox_select_row(value instance_, value row) {
  CAMLparam2(instance_, row);
  gtk_list_box_select_row(GObject_val(instance_), GObject_val(row));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ListBox_set_activate_on_single_click(value instance_, value single) {
  CAMLparam2(instance_, single);
  gtk_list_box_set_activate_on_single_click(GObject_val(instance_), Bool_val(single));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ListBox_set_adjustment(value instance_, value adjustment) {
  CAMLparam2(instance_, adjustment);
  gtk_list_box_set_adjustment(GObject_val(instance_), GObject_val(adjustment));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ListBox_set_placeholder(value instance_, value placeholder) {
  CAMLparam2(instance_, placeholder);
  gtk_list_box_set_placeholder(GObject_val(instance_), GObject_val(placeholder));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ListBox_set_selection_mode(value instance_, value mode) {
  CAMLparam2(instance_, mode);
  gtk_list_box_set_selection_mode(GObject_val(instance_), Int_val(mode));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ListBox_set_show_separators(value instance_, value show_separators) {
  CAMLparam2(instance_, show_separators);
  gtk_list_box_set_show_separators(GObject_val(instance_), Bool_val(show_separators));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ListBox_unselect_all(value instance_) {
  CAMLparam1(instance_);
  gtk_list_box_unselect_all(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ListBox_unselect_row(value instance_, value row) {
  CAMLparam2(instance_, row);
  gtk_list_box_unselect_row(GObject_val(instance_), GObject_val(row));
  CAMLreturn(Val_unit);
}

void ml_Gtk_ListBox_signal_handler_activate_cursor_row(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_ListBox_signal_connect_activate_cursor_row(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "activate-cursor-row", ml_Gtk_ListBox_signal_handler_activate_cursor_row, callback);
}

void ml_Gtk_ListBox_signal_handler_move_cursor(GObject *instance_, int object, gint32 p0, gboolean p1, gboolean p2, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 4);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_int(object);
  args[1] = Val_long(p0);
  args[2] = (p1 ? Val_true : Val_false);
  args[3] = (p2 ? Val_true : Val_false);
  ;caml_callbackN(*callbackCell, 4, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_ListBox_signal_connect_move_cursor(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "move-cursor", ml_Gtk_ListBox_signal_handler_move_cursor, callback);
}

void ml_Gtk_ListBox_signal_handler_row_activated(GObject *instance_, void * row, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(row));
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_ListBox_signal_connect_row_activated(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "row-activated", ml_Gtk_ListBox_signal_handler_row_activated, callback);
}

void ml_Gtk_ListBox_signal_handler_row_selected(GObject *instance_, void * row, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(row));
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_ListBox_signal_connect_row_selected(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "row-selected", ml_Gtk_ListBox_signal_handler_row_selected, callback);
}

void ml_Gtk_ListBox_signal_handler_select_all(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_ListBox_signal_connect_select_all(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "select-all", ml_Gtk_ListBox_signal_handler_select_all, callback);
}

void ml_Gtk_ListBox_signal_handler_selected_rows_changed(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_ListBox_signal_connect_selected_rows_changed(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "selected-rows-changed", ml_Gtk_ListBox_signal_handler_selected_rows_changed, callback);
}

void ml_Gtk_ListBox_signal_handler_toggle_cursor_row(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_ListBox_signal_connect_toggle_cursor_row(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "toggle-cursor-row", ml_Gtk_ListBox_signal_handler_toggle_cursor_row, callback);
}

void ml_Gtk_ListBox_signal_handler_unselect_all(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_ListBox_signal_connect_unselect_all(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "unselect-all", ml_Gtk_ListBox_signal_handler_unselect_all, callback);
}

CAMLprim value ml_Gtk_ListBoxRow_new() {
  CAMLparam0();
  void * result = gtk_list_box_row_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ListBoxRow_changed(value instance_) {
  CAMLparam1(instance_);
  gtk_list_box_row_changed(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ListBoxRow_get_activatable(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_list_box_row_get_activatable(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ListBoxRow_get_child(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_list_box_row_get_child(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ListBoxRow_get_header(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_list_box_row_get_header(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ListBoxRow_get_index(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_list_box_row_get_index(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_ListBoxRow_get_selectable(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_list_box_row_get_selectable(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ListBoxRow_is_selected(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_list_box_row_is_selected(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ListBoxRow_set_activatable(value instance_, value activatable) {
  CAMLparam2(instance_, activatable);
  gtk_list_box_row_set_activatable(GObject_val(instance_), Bool_val(activatable));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ListBoxRow_set_child(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_list_box_row_set_child(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ListBoxRow_set_header(value instance_, value header) {
  CAMLparam2(instance_, header);
  gtk_list_box_row_set_header(GObject_val(instance_), GObject_val(header));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ListBoxRow_set_selectable(value instance_, value selectable) {
  CAMLparam2(instance_, selectable);
  gtk_list_box_row_set_selectable(GObject_val(instance_), Bool_val(selectable));
  CAMLreturn(Val_unit);
}

void ml_Gtk_ListBoxRow_signal_handler_activate(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_ListBoxRow_signal_connect_activate(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "activate", ml_Gtk_ListBoxRow_signal_handler_activate, callback);
}

CAMLprim value ml_Gtk_ListItem_get_activatable(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_list_item_get_activatable(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ListItem_get_child(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_list_item_get_child(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ListItem_get_item(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_list_item_get_item(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ListItem_get_position(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_list_item_get_position(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_ListItem_get_selectable(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_list_item_get_selectable(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ListItem_get_selected(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_list_item_get_selected(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ListItem_set_activatable(value instance_, value activatable) {
  CAMLparam2(instance_, activatable);
  gtk_list_item_set_activatable(GObject_val(instance_), Bool_val(activatable));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ListItem_set_child(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_list_item_set_child(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ListItem_set_selectable(value instance_, value selectable) {
  CAMLparam2(instance_, selectable);
  gtk_list_item_set_selectable(GObject_val(instance_), Bool_val(selectable));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ListStore_clear(value instance_) {
  CAMLparam1(instance_);
  gtk_list_store_clear(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ListView_get_enable_rubberband(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_list_view_get_enable_rubberband(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ListView_get_factory(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_list_view_get_factory(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ListView_get_show_separators(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_list_view_get_show_separators(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ListView_get_single_click_activate(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_list_view_get_single_click_activate(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ListView_set_enable_rubberband(value instance_, value enable_rubberband) {
  CAMLparam2(instance_, enable_rubberband);
  gtk_list_view_set_enable_rubberband(GObject_val(instance_), Bool_val(enable_rubberband));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ListView_set_factory(value instance_, value factory) {
  CAMLparam2(instance_, factory);
  gtk_list_view_set_factory(GObject_val(instance_), GObject_val(factory));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ListView_set_show_separators(value instance_, value show_separators) {
  CAMLparam2(instance_, show_separators);
  gtk_list_view_set_show_separators(GObject_val(instance_), Bool_val(show_separators));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ListView_set_single_click_activate(value instance_, value single_click_activate) {
  CAMLparam2(instance_, single_click_activate);
  gtk_list_view_set_single_click_activate(GObject_val(instance_), Bool_val(single_click_activate));
  CAMLreturn(Val_unit);
}

void ml_Gtk_ListView_signal_handler_activate(GObject *instance_, guint32 position, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_long(position);
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_ListView_signal_connect_activate(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "activate", ml_Gtk_ListView_signal_handler_activate, callback);
}

CAMLprim value ml_Gtk_LockButton_new(value permission) {
  CAMLparam1(permission);
  void * result = gtk_lock_button_new(GObject_val(permission));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_LockButton_get_permission(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_lock_button_get_permission(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_LockButton_set_permission(value instance_, value permission) {
  CAMLparam2(instance_, permission);
  gtk_lock_button_set_permission(GObject_val(instance_), GObject_val(permission));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_MapListModel_has_map(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_map_list_model_has_map(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_MediaControls_new(value stream) {
  CAMLparam1(stream);
  void * result = gtk_media_controls_new(GObject_val(stream));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_MediaControls_get_media_stream(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_media_controls_get_media_stream(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_MediaControls_set_media_stream(value instance_, value stream) {
  CAMLparam2(instance_, stream);
  gtk_media_controls_set_media_stream(GObject_val(instance_), GObject_val(stream));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_MediaFile_new() {
  CAMLparam0();
  void * result = gtk_media_file_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_MediaFile_new_for_input_stream(value stream) {
  CAMLparam1(stream);
  void * result = gtk_media_file_new_for_input_stream(GObject_val(stream));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_MediaFile_new_for_resource(value resource_path) {
  CAMLparam1(resource_path);
  void * result = gtk_media_file_new_for_resource(String_val(resource_path));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_MediaFile_clear(value instance_) {
  CAMLparam1(instance_);
  gtk_media_file_clear(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_MediaFile_get_input_stream(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_media_file_get_input_stream(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_MediaFile_set_input_stream(value instance_, value stream) {
  CAMLparam2(instance_, stream);
  gtk_media_file_set_input_stream(GObject_val(instance_), GObject_val(stream));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_MediaFile_set_resource(value instance_, value resource_path) {
  CAMLparam2(instance_, resource_path);
  gtk_media_file_set_resource(GObject_val(instance_), String_val(resource_path));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_MediaStream_get_ended(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_media_stream_get_ended(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_MediaStream_get_loop(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_media_stream_get_loop(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_MediaStream_get_muted(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_media_stream_get_muted(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_MediaStream_get_playing(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_media_stream_get_playing(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_MediaStream_has_audio(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_media_stream_has_audio(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_MediaStream_has_video(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_media_stream_has_video(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_MediaStream_is_prepared(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_media_stream_is_prepared(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_MediaStream_is_seekable(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_media_stream_is_seekable(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_MediaStream_is_seeking(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_media_stream_is_seeking(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_MediaStream_pause(value instance_) {
  CAMLparam1(instance_);
  gtk_media_stream_pause(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_MediaStream_play(value instance_) {
  CAMLparam1(instance_);
  gtk_media_stream_play(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_MediaStream_realize(value instance_, value surface) {
  CAMLparam2(instance_, surface);
  gtk_media_stream_realize(GObject_val(instance_), GObject_val(surface));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_MediaStream_seek_failed(value instance_) {
  CAMLparam1(instance_);
  gtk_media_stream_seek_failed(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_MediaStream_seek_success(value instance_) {
  CAMLparam1(instance_);
  gtk_media_stream_seek_success(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_MediaStream_set_loop(value instance_, value loop) {
  CAMLparam2(instance_, loop);
  gtk_media_stream_set_loop(GObject_val(instance_), Bool_val(loop));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_MediaStream_set_muted(value instance_, value muted) {
  CAMLparam2(instance_, muted);
  gtk_media_stream_set_muted(GObject_val(instance_), Bool_val(muted));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_MediaStream_set_playing(value instance_, value playing) {
  CAMLparam2(instance_, playing);
  gtk_media_stream_set_playing(GObject_val(instance_), Bool_val(playing));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_MediaStream_stream_ended(value instance_) {
  CAMLparam1(instance_);
  gtk_media_stream_stream_ended(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_MediaStream_stream_unprepared(value instance_) {
  CAMLparam1(instance_);
  gtk_media_stream_stream_unprepared(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_MediaStream_unrealize(value instance_, value surface) {
  CAMLparam2(instance_, surface);
  gtk_media_stream_unrealize(GObject_val(instance_), GObject_val(surface));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_MenuButton_new() {
  CAMLparam0();
  void * result = gtk_menu_button_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_MenuButton_get_always_show_arrow(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_menu_button_get_always_show_arrow(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_MenuButton_get_child(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_menu_button_get_child(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_MenuButton_get_direction(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_menu_button_get_direction(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_MenuButton_get_has_frame(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_menu_button_get_has_frame(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_MenuButton_get_menu_model(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_menu_button_get_menu_model(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_MenuButton_get_popover(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_menu_button_get_popover(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_MenuButton_get_primary(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_menu_button_get_primary(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_MenuButton_get_use_underline(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_menu_button_get_use_underline(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_MenuButton_popdown(value instance_) {
  CAMLparam1(instance_);
  gtk_menu_button_popdown(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_MenuButton_popup(value instance_) {
  CAMLparam1(instance_);
  gtk_menu_button_popup(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_MenuButton_set_always_show_arrow(value instance_, value always_show_arrow) {
  CAMLparam2(instance_, always_show_arrow);
  gtk_menu_button_set_always_show_arrow(GObject_val(instance_), Bool_val(always_show_arrow));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_MenuButton_set_child(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_menu_button_set_child(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_MenuButton_set_direction(value instance_, value direction) {
  CAMLparam2(instance_, direction);
  gtk_menu_button_set_direction(GObject_val(instance_), Int_val(direction));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_MenuButton_set_has_frame(value instance_, value has_frame) {
  CAMLparam2(instance_, has_frame);
  gtk_menu_button_set_has_frame(GObject_val(instance_), Bool_val(has_frame));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_MenuButton_set_icon_name(value instance_, value icon_name) {
  CAMLparam2(instance_, icon_name);
  gtk_menu_button_set_icon_name(GObject_val(instance_), String_val(icon_name));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_MenuButton_set_label(value instance_, value label) {
  CAMLparam2(instance_, label);
  gtk_menu_button_set_label(GObject_val(instance_), String_val(label));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_MenuButton_set_menu_model(value instance_, value menu_model) {
  CAMLparam2(instance_, menu_model);
  gtk_menu_button_set_menu_model(GObject_val(instance_), GObject_val(menu_model));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_MenuButton_set_popover(value instance_, value popover) {
  CAMLparam2(instance_, popover);
  gtk_menu_button_set_popover(GObject_val(instance_), GObject_val(popover));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_MenuButton_set_primary(value instance_, value primary) {
  CAMLparam2(instance_, primary);
  gtk_menu_button_set_primary(GObject_val(instance_), Bool_val(primary));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_MenuButton_set_use_underline(value instance_, value use_underline) {
  CAMLparam2(instance_, use_underline);
  gtk_menu_button_set_use_underline(GObject_val(instance_), Bool_val(use_underline));
  CAMLreturn(Val_unit);
}

void ml_Gtk_MenuButton_signal_handler_activate(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_MenuButton_signal_connect_activate(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "activate", ml_Gtk_MenuButton_signal_handler_activate, callback);
}

CAMLprim value ml_Gtk_MessageDialog_get_message_area(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_message_dialog_get_message_area(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_MessageDialog_set_markup(value instance_, value str) {
  CAMLparam2(instance_, str);
  gtk_message_dialog_set_markup(GObject_val(instance_), String_val(str));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_MnemonicTrigger_new(value keyval) {
  CAMLparam1(keyval);
  void * result = gtk_mnemonic_trigger_new(Long_val(keyval));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_MnemonicTrigger_get_keyval(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_mnemonic_trigger_get_keyval(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_MountOperation_new(value parent) {
  CAMLparam1(parent);
  void * result = gtk_mount_operation_new(GObject_val(parent));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_MountOperation_get_display(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_mount_operation_get_display(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_MountOperation_get_parent(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_mount_operation_get_parent(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_MountOperation_is_showing(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_mount_operation_is_showing(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_MountOperation_set_display(value instance_, value display) {
  CAMLparam2(instance_, display);
  gtk_mount_operation_set_display(GObject_val(instance_), GObject_val(display));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_MountOperation_set_parent(value instance_, value parent) {
  CAMLparam2(instance_, parent);
  gtk_mount_operation_set_parent(GObject_val(instance_), GObject_val(parent));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_MultiFilter_remove(value instance_, value position) {
  CAMLparam2(instance_, position);
  gtk_multi_filter_remove(GObject_val(instance_), Long_val(position));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_MultiSorter_new() {
  CAMLparam0();
  void * result = gtk_multi_sorter_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_MultiSorter_remove(value instance_, value position) {
  CAMLparam2(instance_, position);
  gtk_multi_sorter_remove(GObject_val(instance_), Long_val(position));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_NamedAction_new(value name) {
  CAMLparam1(name);
  void * result = gtk_named_action_new(String_val(name));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_NativeDialog_destroy(value instance_) {
  CAMLparam1(instance_);
  gtk_native_dialog_destroy(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_NativeDialog_get_modal(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_native_dialog_get_modal(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_NativeDialog_get_transient_for(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_native_dialog_get_transient_for(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_NativeDialog_get_visible(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_native_dialog_get_visible(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_NativeDialog_hide(value instance_) {
  CAMLparam1(instance_);
  gtk_native_dialog_hide(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_NativeDialog_set_modal(value instance_, value modal) {
  CAMLparam2(instance_, modal);
  gtk_native_dialog_set_modal(GObject_val(instance_), Bool_val(modal));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_NativeDialog_set_title(value instance_, value title) {
  CAMLparam2(instance_, title);
  gtk_native_dialog_set_title(GObject_val(instance_), String_val(title));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_NativeDialog_set_transient_for(value instance_, value parent) {
  CAMLparam2(instance_, parent);
  gtk_native_dialog_set_transient_for(GObject_val(instance_), GObject_val(parent));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_NativeDialog_show(value instance_) {
  CAMLparam1(instance_);
  gtk_native_dialog_show(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

void ml_Gtk_NativeDialog_signal_handler_response(GObject *instance_, gint32 response_id, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_long(response_id);
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_NativeDialog_signal_connect_response(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "response", ml_Gtk_NativeDialog_signal_handler_response, callback);
}

CAMLprim value ml_Gtk_Notebook_new() {
  CAMLparam0();
  void * result = gtk_notebook_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Notebook_append_page(value instance_, value child, value tab_label) {
  CAMLparam3(instance_, child, tab_label);
  gint32 result = gtk_notebook_append_page(GObject_val(instance_), GObject_val(child), GObject_val(tab_label));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Notebook_append_page_menu(value instance_, value child, value tab_label, value menu_label) {
  CAMLparam4(instance_, child, tab_label, menu_label);
  gint32 result = gtk_notebook_append_page_menu(GObject_val(instance_), GObject_val(child), GObject_val(tab_label), GObject_val(menu_label));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Notebook_detach_tab(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_notebook_detach_tab(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Notebook_get_action_widget(value instance_, value pack_type) {
  CAMLparam2(instance_, pack_type);
  void * result = gtk_notebook_get_action_widget(GObject_val(instance_), Int_val(pack_type));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Notebook_get_current_page(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_notebook_get_current_page(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Notebook_get_menu_label(value instance_, value child) {
  CAMLparam2(instance_, child);
  void * result = gtk_notebook_get_menu_label(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Notebook_get_n_pages(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_notebook_get_n_pages(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Notebook_get_nth_page(value instance_, value page_num) {
  CAMLparam2(instance_, page_num);
  void * result = gtk_notebook_get_nth_page(GObject_val(instance_), Long_val(page_num));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Notebook_get_page(value instance_, value child) {
  CAMLparam2(instance_, child);
  void * result = gtk_notebook_get_page(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Notebook_get_scrollable(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_notebook_get_scrollable(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Notebook_get_show_border(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_notebook_get_show_border(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Notebook_get_show_tabs(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_notebook_get_show_tabs(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Notebook_get_tab_detachable(value instance_, value child) {
  CAMLparam2(instance_, child);
  gboolean result = gtk_notebook_get_tab_detachable(GObject_val(instance_), GObject_val(child));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Notebook_get_tab_label(value instance_, value child) {
  CAMLparam2(instance_, child);
  void * result = gtk_notebook_get_tab_label(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Notebook_get_tab_pos(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_notebook_get_tab_pos(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_Notebook_get_tab_reorderable(value instance_, value child) {
  CAMLparam2(instance_, child);
  gboolean result = gtk_notebook_get_tab_reorderable(GObject_val(instance_), GObject_val(child));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Notebook_insert_page(value instance_, value child, value tab_label, value position) {
  CAMLparam4(instance_, child, tab_label, position);
  gint32 result = gtk_notebook_insert_page(GObject_val(instance_), GObject_val(child), GObject_val(tab_label), Long_val(position));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Notebook_insert_page_menu(value instance_, value child, value tab_label, value menu_label, value position) {
  CAMLparam5(instance_, child, tab_label, menu_label, position);
  gint32 result = gtk_notebook_insert_page_menu(GObject_val(instance_), GObject_val(child), GObject_val(tab_label), GObject_val(menu_label), Long_val(position));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Notebook_next_page(value instance_) {
  CAMLparam1(instance_);
  gtk_notebook_next_page(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Notebook_page_num(value instance_, value child) {
  CAMLparam2(instance_, child);
  gint32 result = gtk_notebook_page_num(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Notebook_popup_disable(value instance_) {
  CAMLparam1(instance_);
  gtk_notebook_popup_disable(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Notebook_popup_enable(value instance_) {
  CAMLparam1(instance_);
  gtk_notebook_popup_enable(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Notebook_prepend_page(value instance_, value child, value tab_label) {
  CAMLparam3(instance_, child, tab_label);
  gint32 result = gtk_notebook_prepend_page(GObject_val(instance_), GObject_val(child), GObject_val(tab_label));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Notebook_prepend_page_menu(value instance_, value child, value tab_label, value menu_label) {
  CAMLparam4(instance_, child, tab_label, menu_label);
  gint32 result = gtk_notebook_prepend_page_menu(GObject_val(instance_), GObject_val(child), GObject_val(tab_label), GObject_val(menu_label));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Notebook_prev_page(value instance_) {
  CAMLparam1(instance_);
  gtk_notebook_prev_page(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Notebook_remove_page(value instance_, value page_num) {
  CAMLparam2(instance_, page_num);
  gtk_notebook_remove_page(GObject_val(instance_), Long_val(page_num));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Notebook_reorder_child(value instance_, value child, value position) {
  CAMLparam3(instance_, child, position);
  gtk_notebook_reorder_child(GObject_val(instance_), GObject_val(child), Long_val(position));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Notebook_set_action_widget(value instance_, value widget, value pack_type) {
  CAMLparam3(instance_, widget, pack_type);
  gtk_notebook_set_action_widget(GObject_val(instance_), GObject_val(widget), Int_val(pack_type));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Notebook_set_current_page(value instance_, value page_num) {
  CAMLparam2(instance_, page_num);
  gtk_notebook_set_current_page(GObject_val(instance_), Long_val(page_num));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Notebook_set_group_name(value instance_, value group_name) {
  CAMLparam2(instance_, group_name);
  gtk_notebook_set_group_name(GObject_val(instance_), String_val(group_name));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Notebook_set_menu_label(value instance_, value child, value menu_label) {
  CAMLparam3(instance_, child, menu_label);
  gtk_notebook_set_menu_label(GObject_val(instance_), GObject_val(child), GObject_val(menu_label));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Notebook_set_menu_label_text(value instance_, value child, value menu_text) {
  CAMLparam3(instance_, child, menu_text);
  gtk_notebook_set_menu_label_text(GObject_val(instance_), GObject_val(child), String_val(menu_text));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Notebook_set_scrollable(value instance_, value scrollable) {
  CAMLparam2(instance_, scrollable);
  gtk_notebook_set_scrollable(GObject_val(instance_), Bool_val(scrollable));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Notebook_set_show_border(value instance_, value show_border) {
  CAMLparam2(instance_, show_border);
  gtk_notebook_set_show_border(GObject_val(instance_), Bool_val(show_border));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Notebook_set_show_tabs(value instance_, value show_tabs) {
  CAMLparam2(instance_, show_tabs);
  gtk_notebook_set_show_tabs(GObject_val(instance_), Bool_val(show_tabs));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Notebook_set_tab_detachable(value instance_, value child, value detachable) {
  CAMLparam3(instance_, child, detachable);
  gtk_notebook_set_tab_detachable(GObject_val(instance_), GObject_val(child), Bool_val(detachable));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Notebook_set_tab_label(value instance_, value child, value tab_label) {
  CAMLparam3(instance_, child, tab_label);
  gtk_notebook_set_tab_label(GObject_val(instance_), GObject_val(child), GObject_val(tab_label));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Notebook_set_tab_label_text(value instance_, value child, value tab_text) {
  CAMLparam3(instance_, child, tab_text);
  gtk_notebook_set_tab_label_text(GObject_val(instance_), GObject_val(child), String_val(tab_text));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Notebook_set_tab_pos(value instance_, value pos) {
  CAMLparam2(instance_, pos);
  gtk_notebook_set_tab_pos(GObject_val(instance_), Int_val(pos));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Notebook_set_tab_reorderable(value instance_, value child, value reorderable) {
  CAMLparam3(instance_, child, reorderable);
  gtk_notebook_set_tab_reorderable(GObject_val(instance_), GObject_val(child), Bool_val(reorderable));
  CAMLreturn(Val_unit);
}

gboolean ml_Gtk_Notebook_signal_handler_change_current_page(GObject *instance_, gint32 object, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_long(object);
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_Notebook_signal_connect_change_current_page(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "change-current-page", ml_Gtk_Notebook_signal_handler_change_current_page, callback);
}

void * ml_Gtk_Notebook_signal_handler_create_window(GObject *instance_, void * page, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(page));
  void * result = GObject_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(void *, result);
}

CAMLprim value ml_Gtk_Notebook_signal_connect_create_window(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "create-window", ml_Gtk_Notebook_signal_handler_create_window, callback);
}

gboolean ml_Gtk_Notebook_signal_handler_focus_tab(GObject *instance_, int object, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_int(object);
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_Notebook_signal_connect_focus_tab(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "focus-tab", ml_Gtk_Notebook_signal_handler_focus_tab, callback);
}

void ml_Gtk_Notebook_signal_handler_move_focus_out(GObject *instance_, int object, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_int(object);
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Notebook_signal_connect_move_focus_out(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "move-focus-out", ml_Gtk_Notebook_signal_handler_move_focus_out, callback);
}

void ml_Gtk_Notebook_signal_handler_page_added(GObject *instance_, void * child, guint32 page_num, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 2);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(child));
  args[1] = Val_long(page_num);
  ;caml_callbackN(*callbackCell, 2, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Notebook_signal_connect_page_added(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "page-added", ml_Gtk_Notebook_signal_handler_page_added, callback);
}

void ml_Gtk_Notebook_signal_handler_page_removed(GObject *instance_, void * child, guint32 page_num, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 2);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(child));
  args[1] = Val_long(page_num);
  ;caml_callbackN(*callbackCell, 2, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Notebook_signal_connect_page_removed(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "page-removed", ml_Gtk_Notebook_signal_handler_page_removed, callback);
}

void ml_Gtk_Notebook_signal_handler_page_reordered(GObject *instance_, void * child, guint32 page_num, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 2);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(child));
  args[1] = Val_long(page_num);
  ;caml_callbackN(*callbackCell, 2, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Notebook_signal_connect_page_reordered(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "page-reordered", ml_Gtk_Notebook_signal_handler_page_reordered, callback);
}

gboolean ml_Gtk_Notebook_signal_handler_reorder_tab(GObject *instance_, int object, gboolean p0, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 2);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_int(object);
  args[1] = (p0 ? Val_true : Val_false);
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 2, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_Notebook_signal_connect_reorder_tab(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "reorder-tab", ml_Gtk_Notebook_signal_handler_reorder_tab, callback);
}

gboolean ml_Gtk_Notebook_signal_handler_select_page(GObject *instance_, gboolean object, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = (object ? Val_true : Val_false);
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_Notebook_signal_connect_select_page(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "select-page", ml_Gtk_Notebook_signal_handler_select_page, callback);
}

void ml_Gtk_Notebook_signal_handler_switch_page(GObject *instance_, void * page, guint32 page_num, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 2);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(page));
  args[1] = Val_long(page_num);
  ;caml_callbackN(*callbackCell, 2, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Notebook_signal_connect_switch_page(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "switch-page", ml_Gtk_Notebook_signal_handler_switch_page, callback);
}

CAMLprim value ml_Gtk_NotebookPage_get_child(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_notebook_page_get_child(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_NumericSorter_get_sort_order(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_numeric_sorter_get_sort_order(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_NumericSorter_set_sort_order(value instance_, value sort_order) {
  CAMLparam2(instance_, sort_order);
  gtk_numeric_sorter_set_sort_order(GObject_val(instance_), Int_val(sort_order));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Overlay_new() {
  CAMLparam0();
  void * result = gtk_overlay_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Overlay_add_overlay(value instance_, value widget) {
  CAMLparam2(instance_, widget);
  gtk_overlay_add_overlay(GObject_val(instance_), GObject_val(widget));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Overlay_get_child(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_overlay_get_child(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Overlay_get_clip_overlay(value instance_, value widget) {
  CAMLparam2(instance_, widget);
  gboolean result = gtk_overlay_get_clip_overlay(GObject_val(instance_), GObject_val(widget));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Overlay_get_measure_overlay(value instance_, value widget) {
  CAMLparam2(instance_, widget);
  gboolean result = gtk_overlay_get_measure_overlay(GObject_val(instance_), GObject_val(widget));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Overlay_remove_overlay(value instance_, value widget) {
  CAMLparam2(instance_, widget);
  gtk_overlay_remove_overlay(GObject_val(instance_), GObject_val(widget));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Overlay_set_child(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_overlay_set_child(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Overlay_set_clip_overlay(value instance_, value widget, value clip_overlay) {
  CAMLparam3(instance_, widget, clip_overlay);
  gtk_overlay_set_clip_overlay(GObject_val(instance_), GObject_val(widget), Bool_val(clip_overlay));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Overlay_set_measure_overlay(value instance_, value widget, value measure) {
  CAMLparam3(instance_, widget, measure);
  gtk_overlay_set_measure_overlay(GObject_val(instance_), GObject_val(widget), Bool_val(measure));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_OverlayLayout_new() {
  CAMLparam0();
  void * result = gtk_overlay_layout_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_OverlayLayoutChild_get_clip_overlay(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_overlay_layout_child_get_clip_overlay(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_OverlayLayoutChild_get_measure(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_overlay_layout_child_get_measure(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_OverlayLayoutChild_set_clip_overlay(value instance_, value clip_overlay) {
  CAMLparam2(instance_, clip_overlay);
  gtk_overlay_layout_child_set_clip_overlay(GObject_val(instance_), Bool_val(clip_overlay));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_OverlayLayoutChild_set_measure(value instance_, value measure) {
  CAMLparam2(instance_, measure);
  gtk_overlay_layout_child_set_measure(GObject_val(instance_), Bool_val(measure));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PageSetup_new() {
  CAMLparam0();
  void * result = gtk_page_setup_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_PageSetup_copy(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_page_setup_copy(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_PageSetup_get_orientation(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_page_setup_get_orientation(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_PageSetup_set_orientation(value instance_, value orientation) {
  CAMLparam2(instance_, orientation);
  gtk_page_setup_set_orientation(GObject_val(instance_), Int_val(orientation));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PageSetupUnixDialog_new(value title, value parent) {
  CAMLparam2(title, parent);
  void * result = gtk_page_setup_unix_dialog_new(String_val(title), GObject_val(parent));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_PageSetupUnixDialog_get_page_setup(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_page_setup_unix_dialog_get_page_setup(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_PageSetupUnixDialog_get_print_settings(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_page_setup_unix_dialog_get_print_settings(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_PageSetupUnixDialog_set_page_setup(value instance_, value page_setup) {
  CAMLparam2(instance_, page_setup);
  gtk_page_setup_unix_dialog_set_page_setup(GObject_val(instance_), GObject_val(page_setup));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PageSetupUnixDialog_set_print_settings(value instance_, value print_settings) {
  CAMLparam2(instance_, print_settings);
  gtk_page_setup_unix_dialog_set_print_settings(GObject_val(instance_), GObject_val(print_settings));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Paned_new(value orientation) {
  CAMLparam1(orientation);
  void * result = gtk_paned_new(Int_val(orientation));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Paned_get_end_child(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_paned_get_end_child(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Paned_get_position(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_paned_get_position(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Paned_get_resize_end_child(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_paned_get_resize_end_child(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Paned_get_resize_start_child(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_paned_get_resize_start_child(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Paned_get_shrink_end_child(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_paned_get_shrink_end_child(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Paned_get_shrink_start_child(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_paned_get_shrink_start_child(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Paned_get_start_child(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_paned_get_start_child(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Paned_get_wide_handle(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_paned_get_wide_handle(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Paned_set_end_child(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_paned_set_end_child(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Paned_set_position(value instance_, value position) {
  CAMLparam2(instance_, position);
  gtk_paned_set_position(GObject_val(instance_), Long_val(position));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Paned_set_resize_end_child(value instance_, value resize) {
  CAMLparam2(instance_, resize);
  gtk_paned_set_resize_end_child(GObject_val(instance_), Bool_val(resize));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Paned_set_resize_start_child(value instance_, value resize) {
  CAMLparam2(instance_, resize);
  gtk_paned_set_resize_start_child(GObject_val(instance_), Bool_val(resize));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Paned_set_shrink_end_child(value instance_, value resize) {
  CAMLparam2(instance_, resize);
  gtk_paned_set_shrink_end_child(GObject_val(instance_), Bool_val(resize));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Paned_set_shrink_start_child(value instance_, value resize) {
  CAMLparam2(instance_, resize);
  gtk_paned_set_shrink_start_child(GObject_val(instance_), Bool_val(resize));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Paned_set_start_child(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_paned_set_start_child(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Paned_set_wide_handle(value instance_, value wide) {
  CAMLparam2(instance_, wide);
  gtk_paned_set_wide_handle(GObject_val(instance_), Bool_val(wide));
  CAMLreturn(Val_unit);
}

gboolean ml_Gtk_Paned_signal_handler_accept_position(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_Paned_signal_connect_accept_position(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "accept-position", ml_Gtk_Paned_signal_handler_accept_position, callback);
}

gboolean ml_Gtk_Paned_signal_handler_cancel_position(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_Paned_signal_connect_cancel_position(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "cancel-position", ml_Gtk_Paned_signal_handler_cancel_position, callback);
}

gboolean ml_Gtk_Paned_signal_handler_cycle_child_focus(GObject *instance_, gboolean reversed, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = (reversed ? Val_true : Val_false);
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_Paned_signal_connect_cycle_child_focus(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "cycle-child-focus", ml_Gtk_Paned_signal_handler_cycle_child_focus, callback);
}

gboolean ml_Gtk_Paned_signal_handler_cycle_handle_focus(GObject *instance_, gboolean reversed, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = (reversed ? Val_true : Val_false);
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_Paned_signal_connect_cycle_handle_focus(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "cycle-handle-focus", ml_Gtk_Paned_signal_handler_cycle_handle_focus, callback);
}

gboolean ml_Gtk_Paned_signal_handler_move_handle(GObject *instance_, int scroll_type, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_int(scroll_type);
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_Paned_signal_connect_move_handle(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "move-handle", ml_Gtk_Paned_signal_handler_move_handle, callback);
}

gboolean ml_Gtk_Paned_signal_handler_toggle_handle_focus(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_Paned_signal_connect_toggle_handle_focus(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "toggle-handle-focus", ml_Gtk_Paned_signal_handler_toggle_handle_focus, callback);
}

CAMLprim value ml_Gtk_PasswordEntry_new() {
  CAMLparam0();
  void * result = gtk_password_entry_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_PasswordEntry_get_extra_menu(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_password_entry_get_extra_menu(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_PasswordEntry_get_show_peek_icon(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_password_entry_get_show_peek_icon(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_PasswordEntry_set_extra_menu(value instance_, value model) {
  CAMLparam2(instance_, model);
  gtk_password_entry_set_extra_menu(GObject_val(instance_), GObject_val(model));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PasswordEntry_set_show_peek_icon(value instance_, value show_peek_icon) {
  CAMLparam2(instance_, show_peek_icon);
  gtk_password_entry_set_show_peek_icon(GObject_val(instance_), Bool_val(show_peek_icon));
  CAMLreturn(Val_unit);
}

void ml_Gtk_PasswordEntry_signal_handler_activate(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_PasswordEntry_signal_connect_activate(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "activate", ml_Gtk_PasswordEntry_signal_handler_activate, callback);
}

CAMLprim value ml_Gtk_PasswordEntryBuffer_new() {
  CAMLparam0();
  void * result = gtk_password_entry_buffer_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Picture_new() {
  CAMLparam0();
  void * result = gtk_picture_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Picture_new_for_resource(value resource_path) {
  CAMLparam1(resource_path);
  void * result = gtk_picture_new_for_resource(String_val(resource_path));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Picture_get_can_shrink(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_picture_get_can_shrink(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Picture_get_keep_aspect_ratio(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_picture_get_keep_aspect_ratio(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Picture_set_alternative_text(value instance_, value alternative_text) {
  CAMLparam2(instance_, alternative_text);
  gtk_picture_set_alternative_text(GObject_val(instance_), String_val(alternative_text));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Picture_set_can_shrink(value instance_, value can_shrink) {
  CAMLparam2(instance_, can_shrink);
  gtk_picture_set_can_shrink(GObject_val(instance_), Bool_val(can_shrink));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Picture_set_keep_aspect_ratio(value instance_, value keep_aspect_ratio) {
  CAMLparam2(instance_, keep_aspect_ratio);
  gtk_picture_set_keep_aspect_ratio(GObject_val(instance_), Bool_val(keep_aspect_ratio));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Picture_set_resource(value instance_, value resource_path) {
  CAMLparam2(instance_, resource_path);
  gtk_picture_set_resource(GObject_val(instance_), String_val(resource_path));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Popover_new() {
  CAMLparam0();
  void * result = gtk_popover_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Popover_get_autohide(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_popover_get_autohide(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Popover_get_cascade_popdown(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_popover_get_cascade_popdown(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Popover_get_child(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_popover_get_child(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Popover_get_has_arrow(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_popover_get_has_arrow(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Popover_get_mnemonics_visible(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_popover_get_mnemonics_visible(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Popover_get_position(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_popover_get_position(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_Popover_popdown(value instance_) {
  CAMLparam1(instance_);
  gtk_popover_popdown(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Popover_popup(value instance_) {
  CAMLparam1(instance_);
  gtk_popover_popup(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Popover_present(value instance_) {
  CAMLparam1(instance_);
  gtk_popover_present(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Popover_set_autohide(value instance_, value autohide) {
  CAMLparam2(instance_, autohide);
  gtk_popover_set_autohide(GObject_val(instance_), Bool_val(autohide));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Popover_set_cascade_popdown(value instance_, value cascade_popdown) {
  CAMLparam2(instance_, cascade_popdown);
  gtk_popover_set_cascade_popdown(GObject_val(instance_), Bool_val(cascade_popdown));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Popover_set_child(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_popover_set_child(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Popover_set_default_widget(value instance_, value widget) {
  CAMLparam2(instance_, widget);
  gtk_popover_set_default_widget(GObject_val(instance_), GObject_val(widget));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Popover_set_has_arrow(value instance_, value has_arrow) {
  CAMLparam2(instance_, has_arrow);
  gtk_popover_set_has_arrow(GObject_val(instance_), Bool_val(has_arrow));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Popover_set_mnemonics_visible(value instance_, value mnemonics_visible) {
  CAMLparam2(instance_, mnemonics_visible);
  gtk_popover_set_mnemonics_visible(GObject_val(instance_), Bool_val(mnemonics_visible));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Popover_set_offset(value instance_, value x_offset, value y_offset) {
  CAMLparam3(instance_, x_offset, y_offset);
  gtk_popover_set_offset(GObject_val(instance_), Long_val(x_offset), Long_val(y_offset));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Popover_set_position(value instance_, value position) {
  CAMLparam2(instance_, position);
  gtk_popover_set_position(GObject_val(instance_), Int_val(position));
  CAMLreturn(Val_unit);
}

void ml_Gtk_Popover_signal_handler_activate_default(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Popover_signal_connect_activate_default(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "activate-default", ml_Gtk_Popover_signal_handler_activate_default, callback);
}

void ml_Gtk_Popover_signal_handler_closed(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Popover_signal_connect_closed(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "closed", ml_Gtk_Popover_signal_handler_closed, callback);
}

CAMLprim value ml_Gtk_PopoverMenu_new_from_model(value model) {
  CAMLparam1(model);
  void * result = gtk_popover_menu_new_from_model(GObject_val(model));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_PopoverMenu_new_from_model_full(value model, value flags) {
  CAMLparam2(model, flags);
  void * result = gtk_popover_menu_new_from_model_full(GObject_val(model), Int_val(flags));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_PopoverMenu_add_child(value instance_, value child, value id) {
  CAMLparam3(instance_, child, id);
  gboolean result = gtk_popover_menu_add_child(GObject_val(instance_), GObject_val(child), String_val(id));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_PopoverMenu_get_menu_model(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_popover_menu_get_menu_model(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_PopoverMenu_remove_child(value instance_, value child) {
  CAMLparam2(instance_, child);
  gboolean result = gtk_popover_menu_remove_child(GObject_val(instance_), GObject_val(child));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_PopoverMenu_set_menu_model(value instance_, value model) {
  CAMLparam2(instance_, model);
  gtk_popover_menu_set_menu_model(GObject_val(instance_), GObject_val(model));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PopoverMenuBar_new_from_model(value model) {
  CAMLparam1(model);
  void * result = gtk_popover_menu_bar_new_from_model(GObject_val(model));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_PopoverMenuBar_add_child(value instance_, value child, value id) {
  CAMLparam3(instance_, child, id);
  gboolean result = gtk_popover_menu_bar_add_child(GObject_val(instance_), GObject_val(child), String_val(id));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_PopoverMenuBar_get_menu_model(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_popover_menu_bar_get_menu_model(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_PopoverMenuBar_remove_child(value instance_, value child) {
  CAMLparam2(instance_, child);
  gboolean result = gtk_popover_menu_bar_remove_child(GObject_val(instance_), GObject_val(child));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_PopoverMenuBar_set_menu_model(value instance_, value model) {
  CAMLparam2(instance_, model);
  gtk_popover_menu_bar_set_menu_model(GObject_val(instance_), GObject_val(model));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintContext_get_page_setup(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_print_context_get_page_setup(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_PrintJob_new(value title, value printer, value settings, value page_setup) {
  CAMLparam4(title, printer, settings, page_setup);
  void * result = gtk_print_job_new(String_val(title), GObject_val(printer), GObject_val(settings), GObject_val(page_setup));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_PrintJob_get_collate(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_print_job_get_collate(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_PrintJob_get_n_up(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_print_job_get_n_up(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_PrintJob_get_n_up_layout(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_print_job_get_n_up_layout(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_PrintJob_get_num_copies(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_print_job_get_num_copies(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_PrintJob_get_page_set(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_print_job_get_page_set(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_PrintJob_get_pages(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_print_job_get_pages(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_PrintJob_get_printer(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_print_job_get_printer(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_PrintJob_get_reverse(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_print_job_get_reverse(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_PrintJob_get_rotate(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_print_job_get_rotate(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_PrintJob_get_settings(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_print_job_get_settings(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_PrintJob_get_status(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_print_job_get_status(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_PrintJob_get_track_print_status(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_print_job_get_track_print_status(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_PrintJob_set_collate(value instance_, value collate) {
  CAMLparam2(instance_, collate);
  gtk_print_job_set_collate(GObject_val(instance_), Bool_val(collate));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintJob_set_n_up(value instance_, value n_up) {
  CAMLparam2(instance_, n_up);
  gtk_print_job_set_n_up(GObject_val(instance_), Long_val(n_up));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintJob_set_n_up_layout(value instance_, value layout) {
  CAMLparam2(instance_, layout);
  gtk_print_job_set_n_up_layout(GObject_val(instance_), Int_val(layout));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintJob_set_num_copies(value instance_, value num_copies) {
  CAMLparam2(instance_, num_copies);
  gtk_print_job_set_num_copies(GObject_val(instance_), Long_val(num_copies));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintJob_set_page_set(value instance_, value page_set) {
  CAMLparam2(instance_, page_set);
  gtk_print_job_set_page_set(GObject_val(instance_), Int_val(page_set));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintJob_set_pages(value instance_, value pages) {
  CAMLparam2(instance_, pages);
  gtk_print_job_set_pages(GObject_val(instance_), Int_val(pages));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintJob_set_reverse(value instance_, value reverse) {
  CAMLparam2(instance_, reverse);
  gtk_print_job_set_reverse(GObject_val(instance_), Bool_val(reverse));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintJob_set_rotate(value instance_, value rotate) {
  CAMLparam2(instance_, rotate);
  gtk_print_job_set_rotate(GObject_val(instance_), Bool_val(rotate));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintJob_set_source_fd(value instance_, value fd) {
  CAMLparam2(instance_, fd);
  CAMLlocal1(exn_msg);
  GError *err = NULL;
  gboolean result = gtk_print_job_set_source_fd(GObject_val(instance_), Long_val(fd), &err);
  if (err) { exn_msg = caml_copy_string(err->message); g_error_free(err); caml_failwith_value(exn_msg); }
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_PrintJob_set_track_print_status(value instance_, value track_status) {
  CAMLparam2(instance_, track_status);
  gtk_print_job_set_track_print_status(GObject_val(instance_), Bool_val(track_status));
  CAMLreturn(Val_unit);
}

void ml_Gtk_PrintJob_signal_handler_status_changed(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_PrintJob_signal_connect_status_changed(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "status-changed", ml_Gtk_PrintJob_signal_handler_status_changed, callback);
}

CAMLprim value ml_Gtk_PrintOperation_new() {
  CAMLparam0();
  void * result = gtk_print_operation_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_PrintOperation_cancel(value instance_) {
  CAMLparam1(instance_);
  gtk_print_operation_cancel(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintOperation_draw_page_finish(value instance_) {
  CAMLparam1(instance_);
  gtk_print_operation_draw_page_finish(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintOperation_get_default_page_setup(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_print_operation_get_default_page_setup(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_PrintOperation_get_embed_page_setup(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_print_operation_get_embed_page_setup(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_PrintOperation_get_error(value instance_) {
  CAMLparam1(instance_);
  CAMLlocal1(exn_msg);
  GError *err = NULL;
  gtk_print_operation_get_error(GObject_val(instance_), &err);
  if (err) { exn_msg = caml_copy_string(err->message); g_error_free(err); caml_failwith_value(exn_msg); }
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintOperation_get_has_selection(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_print_operation_get_has_selection(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_PrintOperation_get_n_pages_to_print(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_print_operation_get_n_pages_to_print(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_PrintOperation_get_print_settings(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_print_operation_get_print_settings(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_PrintOperation_get_status(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_print_operation_get_status(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_PrintOperation_get_support_selection(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_print_operation_get_support_selection(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_PrintOperation_is_finished(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_print_operation_is_finished(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_PrintOperation_run(value instance_, value action, value parent) {
  CAMLparam3(instance_, action, parent);
  CAMLlocal1(exn_msg);
  GError *err = NULL;
  int result = gtk_print_operation_run(GObject_val(instance_), Int_val(action), GObject_val(parent), &err);
  if (err) { exn_msg = caml_copy_string(err->message); g_error_free(err); caml_failwith_value(exn_msg); }
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_PrintOperation_set_allow_async(value instance_, value allow_async) {
  CAMLparam2(instance_, allow_async);
  gtk_print_operation_set_allow_async(GObject_val(instance_), Bool_val(allow_async));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintOperation_set_current_page(value instance_, value current_page) {
  CAMLparam2(instance_, current_page);
  gtk_print_operation_set_current_page(GObject_val(instance_), Long_val(current_page));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintOperation_set_custom_tab_label(value instance_, value label) {
  CAMLparam2(instance_, label);
  gtk_print_operation_set_custom_tab_label(GObject_val(instance_), String_val(label));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintOperation_set_default_page_setup(value instance_, value default_page_setup) {
  CAMLparam2(instance_, default_page_setup);
  gtk_print_operation_set_default_page_setup(GObject_val(instance_), GObject_val(default_page_setup));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintOperation_set_defer_drawing(value instance_) {
  CAMLparam1(instance_);
  gtk_print_operation_set_defer_drawing(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintOperation_set_embed_page_setup(value instance_, value embed) {
  CAMLparam2(instance_, embed);
  gtk_print_operation_set_embed_page_setup(GObject_val(instance_), Bool_val(embed));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintOperation_set_has_selection(value instance_, value has_selection) {
  CAMLparam2(instance_, has_selection);
  gtk_print_operation_set_has_selection(GObject_val(instance_), Bool_val(has_selection));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintOperation_set_job_name(value instance_, value job_name) {
  CAMLparam2(instance_, job_name);
  gtk_print_operation_set_job_name(GObject_val(instance_), String_val(job_name));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintOperation_set_n_pages(value instance_, value n_pages) {
  CAMLparam2(instance_, n_pages);
  gtk_print_operation_set_n_pages(GObject_val(instance_), Long_val(n_pages));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintOperation_set_print_settings(value instance_, value print_settings) {
  CAMLparam2(instance_, print_settings);
  gtk_print_operation_set_print_settings(GObject_val(instance_), GObject_val(print_settings));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintOperation_set_show_progress(value instance_, value show_progress) {
  CAMLparam2(instance_, show_progress);
  gtk_print_operation_set_show_progress(GObject_val(instance_), Bool_val(show_progress));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintOperation_set_support_selection(value instance_, value support_selection) {
  CAMLparam2(instance_, support_selection);
  gtk_print_operation_set_support_selection(GObject_val(instance_), Bool_val(support_selection));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintOperation_set_track_print_status(value instance_, value track_status) {
  CAMLparam2(instance_, track_status);
  gtk_print_operation_set_track_print_status(GObject_val(instance_), Bool_val(track_status));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintOperation_set_unit(value instance_, value unit) {
  CAMLparam2(instance_, unit);
  gtk_print_operation_set_unit(GObject_val(instance_), Int_val(unit));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintOperation_set_use_full_page(value instance_, value full_page) {
  CAMLparam2(instance_, full_page);
  gtk_print_operation_set_use_full_page(GObject_val(instance_), Bool_val(full_page));
  CAMLreturn(Val_unit);
}

void ml_Gtk_PrintOperation_signal_handler_begin_print(GObject *instance_, void * context, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(context));
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_PrintOperation_signal_connect_begin_print(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "begin-print", ml_Gtk_PrintOperation_signal_handler_begin_print, callback);
}

void * ml_Gtk_PrintOperation_signal_handler_create_custom_widget(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  void * result = GObject_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(void *, result);
}

CAMLprim value ml_Gtk_PrintOperation_signal_connect_create_custom_widget(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "create-custom-widget", ml_Gtk_PrintOperation_signal_handler_create_custom_widget, callback);
}

void ml_Gtk_PrintOperation_signal_handler_custom_widget_apply(GObject *instance_, void * widget, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(widget));
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_PrintOperation_signal_connect_custom_widget_apply(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "custom-widget-apply", ml_Gtk_PrintOperation_signal_handler_custom_widget_apply, callback);
}

void ml_Gtk_PrintOperation_signal_handler_done(GObject *instance_, int result, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_int(result);
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_PrintOperation_signal_connect_done(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "done", ml_Gtk_PrintOperation_signal_handler_done, callback);
}

void ml_Gtk_PrintOperation_signal_handler_draw_page(GObject *instance_, void * context, gint32 page_nr, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 2);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(context));
  args[1] = Val_long(page_nr);
  ;caml_callbackN(*callbackCell, 2, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_PrintOperation_signal_connect_draw_page(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "draw-page", ml_Gtk_PrintOperation_signal_handler_draw_page, callback);
}

void ml_Gtk_PrintOperation_signal_handler_end_print(GObject *instance_, void * context, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(context));
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_PrintOperation_signal_connect_end_print(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "end-print", ml_Gtk_PrintOperation_signal_handler_end_print, callback);
}

gboolean ml_Gtk_PrintOperation_signal_handler_paginate(GObject *instance_, void * context, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(context));
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_PrintOperation_signal_connect_paginate(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "paginate", ml_Gtk_PrintOperation_signal_handler_paginate, callback);
}

void ml_Gtk_PrintOperation_signal_handler_request_page_setup(GObject *instance_, void * context, gint32 page_nr, void * setup, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 3);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(context));
  args[1] = Val_long(page_nr);
  args[2] = Val_GObject((void *)(setup));
  ;caml_callbackN(*callbackCell, 3, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_PrintOperation_signal_connect_request_page_setup(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "request-page-setup", ml_Gtk_PrintOperation_signal_handler_request_page_setup, callback);
}

void ml_Gtk_PrintOperation_signal_handler_status_changed(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_PrintOperation_signal_connect_status_changed(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "status-changed", ml_Gtk_PrintOperation_signal_handler_status_changed, callback);
}

void ml_Gtk_PrintOperation_signal_handler_update_custom_widget(GObject *instance_, void * widget, void * setup, void * settings, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 3);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(widget));
  args[1] = Val_GObject((void *)(setup));
  args[2] = Val_GObject((void *)(settings));
  ;caml_callbackN(*callbackCell, 3, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_PrintOperation_signal_connect_update_custom_widget(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "update-custom-widget", ml_Gtk_PrintOperation_signal_handler_update_custom_widget, callback);
}

CAMLprim value ml_Gtk_PrintSettings_new() {
  CAMLparam0();
  void * result = gtk_print_settings_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_PrintSettings_copy(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_print_settings_copy(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_PrintSettings_get_bool(value instance_, value key) {
  CAMLparam2(instance_, key);
  gboolean result = gtk_print_settings_get_bool(GObject_val(instance_), String_val(key));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_PrintSettings_get_collate(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_print_settings_get_collate(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_PrintSettings_get_duplex(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_print_settings_get_duplex(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_PrintSettings_get_int(value instance_, value key) {
  CAMLparam2(instance_, key);
  gint32 result = gtk_print_settings_get_int(GObject_val(instance_), String_val(key));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_PrintSettings_get_int_with_default(value instance_, value key, value def) {
  CAMLparam3(instance_, key, def);
  gint32 result = gtk_print_settings_get_int_with_default(GObject_val(instance_), String_val(key), Long_val(def));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_PrintSettings_get_n_copies(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_print_settings_get_n_copies(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_PrintSettings_get_number_up(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_print_settings_get_number_up(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_PrintSettings_get_number_up_layout(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_print_settings_get_number_up_layout(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_PrintSettings_get_orientation(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_print_settings_get_orientation(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_PrintSettings_get_page_set(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_print_settings_get_page_set(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_PrintSettings_get_print_pages(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_print_settings_get_print_pages(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_PrintSettings_get_quality(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_print_settings_get_quality(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_PrintSettings_get_resolution(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_print_settings_get_resolution(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_PrintSettings_get_resolution_x(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_print_settings_get_resolution_x(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_PrintSettings_get_resolution_y(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_print_settings_get_resolution_y(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_PrintSettings_get_reverse(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_print_settings_get_reverse(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_PrintSettings_get_use_color(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_print_settings_get_use_color(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_PrintSettings_has_key(value instance_, value key) {
  CAMLparam2(instance_, key);
  gboolean result = gtk_print_settings_has_key(GObject_val(instance_), String_val(key));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_PrintSettings_set(value instance_, value key, value _value) {
  CAMLparam3(instance_, key, _value);
  gtk_print_settings_set(GObject_val(instance_), String_val(key), String_val(_value));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintSettings_set_bool(value instance_, value key, value _value) {
  CAMLparam3(instance_, key, _value);
  gtk_print_settings_set_bool(GObject_val(instance_), String_val(key), Bool_val(_value));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintSettings_set_collate(value instance_, value collate) {
  CAMLparam2(instance_, collate);
  gtk_print_settings_set_collate(GObject_val(instance_), Bool_val(collate));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintSettings_set_default_source(value instance_, value default_source) {
  CAMLparam2(instance_, default_source);
  gtk_print_settings_set_default_source(GObject_val(instance_), String_val(default_source));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintSettings_set_dither(value instance_, value dither) {
  CAMLparam2(instance_, dither);
  gtk_print_settings_set_dither(GObject_val(instance_), String_val(dither));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintSettings_set_duplex(value instance_, value duplex) {
  CAMLparam2(instance_, duplex);
  gtk_print_settings_set_duplex(GObject_val(instance_), Int_val(duplex));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintSettings_set_finishings(value instance_, value finishings) {
  CAMLparam2(instance_, finishings);
  gtk_print_settings_set_finishings(GObject_val(instance_), String_val(finishings));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintSettings_set_int(value instance_, value key, value _value) {
  CAMLparam3(instance_, key, _value);
  gtk_print_settings_set_int(GObject_val(instance_), String_val(key), Long_val(_value));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintSettings_set_media_type(value instance_, value media_type) {
  CAMLparam2(instance_, media_type);
  gtk_print_settings_set_media_type(GObject_val(instance_), String_val(media_type));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintSettings_set_n_copies(value instance_, value num_copies) {
  CAMLparam2(instance_, num_copies);
  gtk_print_settings_set_n_copies(GObject_val(instance_), Long_val(num_copies));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintSettings_set_number_up(value instance_, value number_up) {
  CAMLparam2(instance_, number_up);
  gtk_print_settings_set_number_up(GObject_val(instance_), Long_val(number_up));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintSettings_set_number_up_layout(value instance_, value number_up_layout) {
  CAMLparam2(instance_, number_up_layout);
  gtk_print_settings_set_number_up_layout(GObject_val(instance_), Int_val(number_up_layout));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintSettings_set_orientation(value instance_, value orientation) {
  CAMLparam2(instance_, orientation);
  gtk_print_settings_set_orientation(GObject_val(instance_), Int_val(orientation));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintSettings_set_output_bin(value instance_, value output_bin) {
  CAMLparam2(instance_, output_bin);
  gtk_print_settings_set_output_bin(GObject_val(instance_), String_val(output_bin));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintSettings_set_page_set(value instance_, value page_set) {
  CAMLparam2(instance_, page_set);
  gtk_print_settings_set_page_set(GObject_val(instance_), Int_val(page_set));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintSettings_set_print_pages(value instance_, value pages) {
  CAMLparam2(instance_, pages);
  gtk_print_settings_set_print_pages(GObject_val(instance_), Int_val(pages));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintSettings_set_printer(value instance_, value printer) {
  CAMLparam2(instance_, printer);
  gtk_print_settings_set_printer(GObject_val(instance_), String_val(printer));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintSettings_set_quality(value instance_, value quality) {
  CAMLparam2(instance_, quality);
  gtk_print_settings_set_quality(GObject_val(instance_), Int_val(quality));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintSettings_set_resolution(value instance_, value resolution) {
  CAMLparam2(instance_, resolution);
  gtk_print_settings_set_resolution(GObject_val(instance_), Long_val(resolution));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintSettings_set_resolution_xy(value instance_, value resolution_x, value resolution_y) {
  CAMLparam3(instance_, resolution_x, resolution_y);
  gtk_print_settings_set_resolution_xy(GObject_val(instance_), Long_val(resolution_x), Long_val(resolution_y));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintSettings_set_reverse(value instance_, value reverse) {
  CAMLparam2(instance_, reverse);
  gtk_print_settings_set_reverse(GObject_val(instance_), Bool_val(reverse));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintSettings_set_use_color(value instance_, value use_color) {
  CAMLparam2(instance_, use_color);
  gtk_print_settings_set_use_color(GObject_val(instance_), Bool_val(use_color));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintSettings_unset(value instance_, value key) {
  CAMLparam2(instance_, key);
  gtk_print_settings_unset(GObject_val(instance_), String_val(key));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintUnixDialog_new(value title, value parent) {
  CAMLparam2(title, parent);
  void * result = gtk_print_unix_dialog_new(String_val(title), GObject_val(parent));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_PrintUnixDialog_add_custom_tab(value instance_, value child, value tab_label) {
  CAMLparam3(instance_, child, tab_label);
  gtk_print_unix_dialog_add_custom_tab(GObject_val(instance_), GObject_val(child), GObject_val(tab_label));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintUnixDialog_get_current_page(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_print_unix_dialog_get_current_page(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_PrintUnixDialog_get_embed_page_setup(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_print_unix_dialog_get_embed_page_setup(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_PrintUnixDialog_get_has_selection(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_print_unix_dialog_get_has_selection(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_PrintUnixDialog_get_page_setup(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_print_unix_dialog_get_page_setup(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_PrintUnixDialog_get_page_setup_set(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_print_unix_dialog_get_page_setup_set(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_PrintUnixDialog_get_selected_printer(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_print_unix_dialog_get_selected_printer(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_PrintUnixDialog_get_settings(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_print_unix_dialog_get_settings(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_PrintUnixDialog_get_support_selection(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_print_unix_dialog_get_support_selection(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_PrintUnixDialog_set_current_page(value instance_, value current_page) {
  CAMLparam2(instance_, current_page);
  gtk_print_unix_dialog_set_current_page(GObject_val(instance_), Long_val(current_page));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintUnixDialog_set_embed_page_setup(value instance_, value embed) {
  CAMLparam2(instance_, embed);
  gtk_print_unix_dialog_set_embed_page_setup(GObject_val(instance_), Bool_val(embed));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintUnixDialog_set_has_selection(value instance_, value has_selection) {
  CAMLparam2(instance_, has_selection);
  gtk_print_unix_dialog_set_has_selection(GObject_val(instance_), Bool_val(has_selection));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintUnixDialog_set_manual_capabilities(value instance_, value capabilities) {
  CAMLparam2(instance_, capabilities);
  gtk_print_unix_dialog_set_manual_capabilities(GObject_val(instance_), Int_val(capabilities));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintUnixDialog_set_page_setup(value instance_, value page_setup) {
  CAMLparam2(instance_, page_setup);
  gtk_print_unix_dialog_set_page_setup(GObject_val(instance_), GObject_val(page_setup));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintUnixDialog_set_settings(value instance_, value settings) {
  CAMLparam2(instance_, settings);
  gtk_print_unix_dialog_set_settings(GObject_val(instance_), GObject_val(settings));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_PrintUnixDialog_set_support_selection(value instance_, value support_selection) {
  CAMLparam2(instance_, support_selection);
  gtk_print_unix_dialog_set_support_selection(GObject_val(instance_), Bool_val(support_selection));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Printer_accepts_pdf(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_printer_accepts_pdf(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Printer_accepts_ps(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_printer_accepts_ps(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Printer_compare(value instance_, value b) {
  CAMLparam2(instance_, b);
  gint32 result = gtk_printer_compare(GObject_val(instance_), GObject_val(b));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Printer_get_default_page_size(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_printer_get_default_page_size(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Printer_get_job_count(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_printer_get_job_count(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Printer_has_details(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_printer_has_details(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Printer_is_accepting_jobs(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_printer_is_accepting_jobs(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Printer_is_active(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_printer_is_active(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Printer_is_default(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_printer_is_default(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Printer_is_paused(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_printer_is_paused(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Printer_is_virtual(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_printer_is_virtual(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Printer_request_details(value instance_) {
  CAMLparam1(instance_);
  gtk_printer_request_details(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

void ml_Gtk_Printer_signal_handler_details_acquired(GObject *instance_, gboolean success, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = (success ? Val_true : Val_false);
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Printer_signal_connect_details_acquired(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "details-acquired", ml_Gtk_Printer_signal_handler_details_acquired, callback);
}

CAMLprim value ml_Gtk_ProgressBar_new() {
  CAMLparam0();
  void * result = gtk_progress_bar_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ProgressBar_get_inverted(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_progress_bar_get_inverted(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ProgressBar_get_show_text(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_progress_bar_get_show_text(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ProgressBar_pulse(value instance_) {
  CAMLparam1(instance_);
  gtk_progress_bar_pulse(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ProgressBar_set_inverted(value instance_, value inverted) {
  CAMLparam2(instance_, inverted);
  gtk_progress_bar_set_inverted(GObject_val(instance_), Bool_val(inverted));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ProgressBar_set_show_text(value instance_, value show_text) {
  CAMLparam2(instance_, show_text);
  gtk_progress_bar_set_show_text(GObject_val(instance_), Bool_val(show_text));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ProgressBar_set_text(value instance_, value text) {
  CAMLparam2(instance_, text);
  gtk_progress_bar_set_text(GObject_val(instance_), String_val(text));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Range_get_adjustment(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_range_get_adjustment(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Range_get_flippable(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_range_get_flippable(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Range_get_inverted(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_range_get_inverted(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Range_get_restrict_to_fill_level(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_range_get_restrict_to_fill_level(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Range_get_round_digits(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_range_get_round_digits(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Range_get_show_fill_level(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_range_get_show_fill_level(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Range_get_slider_size_fixed(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_range_get_slider_size_fixed(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Range_set_adjustment(value instance_, value adjustment) {
  CAMLparam2(instance_, adjustment);
  gtk_range_set_adjustment(GObject_val(instance_), GObject_val(adjustment));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Range_set_flippable(value instance_, value flippable) {
  CAMLparam2(instance_, flippable);
  gtk_range_set_flippable(GObject_val(instance_), Bool_val(flippable));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Range_set_inverted(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_range_set_inverted(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Range_set_restrict_to_fill_level(value instance_, value restrict_to_fill_level) {
  CAMLparam2(instance_, restrict_to_fill_level);
  gtk_range_set_restrict_to_fill_level(GObject_val(instance_), Bool_val(restrict_to_fill_level));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Range_set_round_digits(value instance_, value round_digits) {
  CAMLparam2(instance_, round_digits);
  gtk_range_set_round_digits(GObject_val(instance_), Long_val(round_digits));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Range_set_show_fill_level(value instance_, value show_fill_level) {
  CAMLparam2(instance_, show_fill_level);
  gtk_range_set_show_fill_level(GObject_val(instance_), Bool_val(show_fill_level));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Range_set_slider_size_fixed(value instance_, value size_fixed) {
  CAMLparam2(instance_, size_fixed);
  gtk_range_set_slider_size_fixed(GObject_val(instance_), Bool_val(size_fixed));
  CAMLreturn(Val_unit);
}

void ml_Gtk_Range_signal_handler_move_slider(GObject *instance_, int step, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_int(step);
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Range_signal_connect_move_slider(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "move-slider", ml_Gtk_Range_signal_handler_move_slider, callback);
}

void ml_Gtk_Range_signal_handler_value_changed(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Range_signal_connect_value_changed(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "value-changed", ml_Gtk_Range_signal_handler_value_changed, callback);
}

CAMLprim value ml_Gtk_RecentManager_new() {
  CAMLparam0();
  void * result = gtk_recent_manager_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_RecentManager_add_item(value instance_, value uri) {
  CAMLparam2(instance_, uri);
  gboolean result = gtk_recent_manager_add_item(GObject_val(instance_), String_val(uri));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_RecentManager_has_item(value instance_, value uri) {
  CAMLparam2(instance_, uri);
  gboolean result = gtk_recent_manager_has_item(GObject_val(instance_), String_val(uri));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_RecentManager_move_item(value instance_, value uri, value new_uri) {
  CAMLparam3(instance_, uri, new_uri);
  CAMLlocal1(exn_msg);
  GError *err = NULL;
  gboolean result = gtk_recent_manager_move_item(GObject_val(instance_), String_val(uri), String_val(new_uri), &err);
  if (err) { exn_msg = caml_copy_string(err->message); g_error_free(err); caml_failwith_value(exn_msg); }
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_RecentManager_purge_items(value instance_) {
  CAMLparam1(instance_);
  CAMLlocal1(exn_msg);
  GError *err = NULL;
  gint32 result = gtk_recent_manager_purge_items(GObject_val(instance_), &err);
  if (err) { exn_msg = caml_copy_string(err->message); g_error_free(err); caml_failwith_value(exn_msg); }
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_RecentManager_remove_item(value instance_, value uri) {
  CAMLparam2(instance_, uri);
  CAMLlocal1(exn_msg);
  GError *err = NULL;
  gboolean result = gtk_recent_manager_remove_item(GObject_val(instance_), String_val(uri), &err);
  if (err) { exn_msg = caml_copy_string(err->message); g_error_free(err); caml_failwith_value(exn_msg); }
  CAMLreturn((result ? Val_true : Val_false));
}

void ml_Gtk_RecentManager_signal_handler_changed(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_RecentManager_signal_connect_changed(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "changed", ml_Gtk_RecentManager_signal_handler_changed, callback);
}

CAMLprim value ml_Gtk_Revealer_new() {
  CAMLparam0();
  void * result = gtk_revealer_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Revealer_get_child(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_revealer_get_child(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Revealer_get_child_revealed(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_revealer_get_child_revealed(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Revealer_get_reveal_child(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_revealer_get_reveal_child(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Revealer_get_transition_duration(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_revealer_get_transition_duration(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Revealer_get_transition_type(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_revealer_get_transition_type(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_Revealer_set_child(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_revealer_set_child(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Revealer_set_reveal_child(value instance_, value reveal_child) {
  CAMLparam2(instance_, reveal_child);
  gtk_revealer_set_reveal_child(GObject_val(instance_), Bool_val(reveal_child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Revealer_set_transition_duration(value instance_, value duration) {
  CAMLparam2(instance_, duration);
  gtk_revealer_set_transition_duration(GObject_val(instance_), Long_val(duration));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Revealer_set_transition_type(value instance_, value transition) {
  CAMLparam2(instance_, transition);
  gtk_revealer_set_transition_type(GObject_val(instance_), Int_val(transition));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Scale_new(value orientation, value adjustment) {
  CAMLparam2(orientation, adjustment);
  void * result = gtk_scale_new(Int_val(orientation), GObject_val(adjustment));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Scale_clear_marks(value instance_) {
  CAMLparam1(instance_);
  gtk_scale_clear_marks(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Scale_get_digits(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_scale_get_digits(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Scale_get_draw_value(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_scale_get_draw_value(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Scale_get_has_origin(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_scale_get_has_origin(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Scale_get_value_pos(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_scale_get_value_pos(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_Scale_set_digits(value instance_, value digits) {
  CAMLparam2(instance_, digits);
  gtk_scale_set_digits(GObject_val(instance_), Long_val(digits));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Scale_set_draw_value(value instance_, value draw_value) {
  CAMLparam2(instance_, draw_value);
  gtk_scale_set_draw_value(GObject_val(instance_), Bool_val(draw_value));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Scale_set_has_origin(value instance_, value has_origin) {
  CAMLparam2(instance_, has_origin);
  gtk_scale_set_has_origin(GObject_val(instance_), Bool_val(has_origin));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Scale_set_value_pos(value instance_, value pos) {
  CAMLparam2(instance_, pos);
  gtk_scale_set_value_pos(GObject_val(instance_), Int_val(pos));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ScaleButton_get_adjustment(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_scale_button_get_adjustment(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ScaleButton_get_minus_button(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_scale_button_get_minus_button(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ScaleButton_get_plus_button(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_scale_button_get_plus_button(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ScaleButton_get_popup(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_scale_button_get_popup(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ScaleButton_set_adjustment(value instance_, value adjustment) {
  CAMLparam2(instance_, adjustment);
  gtk_scale_button_set_adjustment(GObject_val(instance_), GObject_val(adjustment));
  CAMLreturn(Val_unit);
}

void ml_Gtk_ScaleButton_signal_handler_popdown(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_ScaleButton_signal_connect_popdown(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "popdown", ml_Gtk_ScaleButton_signal_handler_popdown, callback);
}

void ml_Gtk_ScaleButton_signal_handler_popup(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_ScaleButton_signal_connect_popup(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "popup", ml_Gtk_ScaleButton_signal_handler_popup, callback);
}

CAMLprim value ml_Gtk_Scrollbar_new(value orientation, value adjustment) {
  CAMLparam2(orientation, adjustment);
  void * result = gtk_scrollbar_new(Int_val(orientation), GObject_val(adjustment));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Scrollbar_get_adjustment(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_scrollbar_get_adjustment(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Scrollbar_set_adjustment(value instance_, value adjustment) {
  CAMLparam2(instance_, adjustment);
  gtk_scrollbar_set_adjustment(GObject_val(instance_), GObject_val(adjustment));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ScrolledWindow_new() {
  CAMLparam0();
  void * result = gtk_scrolled_window_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ScrolledWindow_get_child(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_scrolled_window_get_child(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ScrolledWindow_get_hadjustment(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_scrolled_window_get_hadjustment(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ScrolledWindow_get_has_frame(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_scrolled_window_get_has_frame(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ScrolledWindow_get_hscrollbar(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_scrolled_window_get_hscrollbar(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ScrolledWindow_get_kinetic_scrolling(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_scrolled_window_get_kinetic_scrolling(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ScrolledWindow_get_max_content_height(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_scrolled_window_get_max_content_height(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_ScrolledWindow_get_max_content_width(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_scrolled_window_get_max_content_width(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_ScrolledWindow_get_min_content_height(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_scrolled_window_get_min_content_height(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_ScrolledWindow_get_min_content_width(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_scrolled_window_get_min_content_width(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_ScrolledWindow_get_overlay_scrolling(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_scrolled_window_get_overlay_scrolling(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ScrolledWindow_get_placement(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_scrolled_window_get_placement(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_ScrolledWindow_get_propagate_natural_height(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_scrolled_window_get_propagate_natural_height(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ScrolledWindow_get_propagate_natural_width(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_scrolled_window_get_propagate_natural_width(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ScrolledWindow_get_vadjustment(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_scrolled_window_get_vadjustment(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ScrolledWindow_get_vscrollbar(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_scrolled_window_get_vscrollbar(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ScrolledWindow_set_child(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_scrolled_window_set_child(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ScrolledWindow_set_hadjustment(value instance_, value hadjustment) {
  CAMLparam2(instance_, hadjustment);
  gtk_scrolled_window_set_hadjustment(GObject_val(instance_), GObject_val(hadjustment));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ScrolledWindow_set_has_frame(value instance_, value has_frame) {
  CAMLparam2(instance_, has_frame);
  gtk_scrolled_window_set_has_frame(GObject_val(instance_), Bool_val(has_frame));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ScrolledWindow_set_kinetic_scrolling(value instance_, value kinetic_scrolling) {
  CAMLparam2(instance_, kinetic_scrolling);
  gtk_scrolled_window_set_kinetic_scrolling(GObject_val(instance_), Bool_val(kinetic_scrolling));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ScrolledWindow_set_max_content_height(value instance_, value height) {
  CAMLparam2(instance_, height);
  gtk_scrolled_window_set_max_content_height(GObject_val(instance_), Long_val(height));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ScrolledWindow_set_max_content_width(value instance_, value width) {
  CAMLparam2(instance_, width);
  gtk_scrolled_window_set_max_content_width(GObject_val(instance_), Long_val(width));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ScrolledWindow_set_min_content_height(value instance_, value height) {
  CAMLparam2(instance_, height);
  gtk_scrolled_window_set_min_content_height(GObject_val(instance_), Long_val(height));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ScrolledWindow_set_min_content_width(value instance_, value width) {
  CAMLparam2(instance_, width);
  gtk_scrolled_window_set_min_content_width(GObject_val(instance_), Long_val(width));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ScrolledWindow_set_overlay_scrolling(value instance_, value overlay_scrolling) {
  CAMLparam2(instance_, overlay_scrolling);
  gtk_scrolled_window_set_overlay_scrolling(GObject_val(instance_), Bool_val(overlay_scrolling));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ScrolledWindow_set_placement(value instance_, value window_placement) {
  CAMLparam2(instance_, window_placement);
  gtk_scrolled_window_set_placement(GObject_val(instance_), Int_val(window_placement));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ScrolledWindow_set_policy(value instance_, value hscrollbar_policy, value vscrollbar_policy) {
  CAMLparam3(instance_, hscrollbar_policy, vscrollbar_policy);
  gtk_scrolled_window_set_policy(GObject_val(instance_), Int_val(hscrollbar_policy), Int_val(vscrollbar_policy));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ScrolledWindow_set_propagate_natural_height(value instance_, value propagate) {
  CAMLparam2(instance_, propagate);
  gtk_scrolled_window_set_propagate_natural_height(GObject_val(instance_), Bool_val(propagate));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ScrolledWindow_set_propagate_natural_width(value instance_, value propagate) {
  CAMLparam2(instance_, propagate);
  gtk_scrolled_window_set_propagate_natural_width(GObject_val(instance_), Bool_val(propagate));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ScrolledWindow_set_vadjustment(value instance_, value vadjustment) {
  CAMLparam2(instance_, vadjustment);
  gtk_scrolled_window_set_vadjustment(GObject_val(instance_), GObject_val(vadjustment));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ScrolledWindow_unset_placement(value instance_) {
  CAMLparam1(instance_);
  gtk_scrolled_window_unset_placement(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

void ml_Gtk_ScrolledWindow_signal_handler_edge_overshot(GObject *instance_, int pos, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_int(pos);
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_ScrolledWindow_signal_connect_edge_overshot(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "edge-overshot", ml_Gtk_ScrolledWindow_signal_handler_edge_overshot, callback);
}

void ml_Gtk_ScrolledWindow_signal_handler_edge_reached(GObject *instance_, int pos, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_int(pos);
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_ScrolledWindow_signal_connect_edge_reached(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "edge-reached", ml_Gtk_ScrolledWindow_signal_handler_edge_reached, callback);
}

void ml_Gtk_ScrolledWindow_signal_handler_move_focus_out(GObject *instance_, int direction_type, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_int(direction_type);
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_ScrolledWindow_signal_connect_move_focus_out(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "move-focus-out", ml_Gtk_ScrolledWindow_signal_handler_move_focus_out, callback);
}

gboolean ml_Gtk_ScrolledWindow_signal_handler_scroll_child(GObject *instance_, int scroll, gboolean horizontal, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 2);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_int(scroll);
  args[1] = (horizontal ? Val_true : Val_false);
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 2, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_ScrolledWindow_signal_connect_scroll_child(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "scroll-child", ml_Gtk_ScrolledWindow_signal_handler_scroll_child, callback);
}

CAMLprim value ml_Gtk_SearchBar_new() {
  CAMLparam0();
  void * result = gtk_search_bar_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_SearchBar_get_child(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_search_bar_get_child(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_SearchBar_get_key_capture_widget(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_search_bar_get_key_capture_widget(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_SearchBar_get_search_mode(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_search_bar_get_search_mode(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_SearchBar_get_show_close_button(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_search_bar_get_show_close_button(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_SearchBar_set_child(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_search_bar_set_child(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_SearchBar_set_key_capture_widget(value instance_, value widget) {
  CAMLparam2(instance_, widget);
  gtk_search_bar_set_key_capture_widget(GObject_val(instance_), GObject_val(widget));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_SearchBar_set_search_mode(value instance_, value search_mode) {
  CAMLparam2(instance_, search_mode);
  gtk_search_bar_set_search_mode(GObject_val(instance_), Bool_val(search_mode));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_SearchBar_set_show_close_button(value instance_, value visible) {
  CAMLparam2(instance_, visible);
  gtk_search_bar_set_show_close_button(GObject_val(instance_), Bool_val(visible));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_SearchEntry_new() {
  CAMLparam0();
  void * result = gtk_search_entry_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_SearchEntry_get_key_capture_widget(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_search_entry_get_key_capture_widget(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_SearchEntry_set_key_capture_widget(value instance_, value widget) {
  CAMLparam2(instance_, widget);
  gtk_search_entry_set_key_capture_widget(GObject_val(instance_), GObject_val(widget));
  CAMLreturn(Val_unit);
}

void ml_Gtk_SearchEntry_signal_handler_activate(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_SearchEntry_signal_connect_activate(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "activate", ml_Gtk_SearchEntry_signal_handler_activate, callback);
}

void ml_Gtk_SearchEntry_signal_handler_next_match(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_SearchEntry_signal_connect_next_match(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "next-match", ml_Gtk_SearchEntry_signal_handler_next_match, callback);
}

void ml_Gtk_SearchEntry_signal_handler_previous_match(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_SearchEntry_signal_connect_previous_match(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "previous-match", ml_Gtk_SearchEntry_signal_handler_previous_match, callback);
}

void ml_Gtk_SearchEntry_signal_handler_search_changed(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_SearchEntry_signal_connect_search_changed(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "search-changed", ml_Gtk_SearchEntry_signal_handler_search_changed, callback);
}

void ml_Gtk_SearchEntry_signal_handler_search_started(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_SearchEntry_signal_connect_search_started(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "search-started", ml_Gtk_SearchEntry_signal_handler_search_started, callback);
}

void ml_Gtk_SearchEntry_signal_handler_stop_search(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_SearchEntry_signal_connect_stop_search(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "stop-search", ml_Gtk_SearchEntry_signal_handler_stop_search, callback);
}

CAMLprim value ml_Gtk_Separator_new(value orientation) {
  CAMLparam1(orientation);
  void * result = gtk_separator_new(Int_val(orientation));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Settings_reset_property(value instance_, value name) {
  CAMLparam2(instance_, name);
  gtk_settings_reset_property(GObject_val(instance_), String_val(name));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Shortcut_get_action(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_shortcut_get_action(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Shortcut_get_trigger(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_shortcut_get_trigger(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ShortcutAction_parse_string(value string) {
  CAMLparam1(string);
  void * result = gtk_shortcut_action_parse_string(String_val(string));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ShortcutController_new() {
  CAMLparam0();
  void * result = gtk_shortcut_controller_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ShortcutController_get_scope(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_shortcut_controller_get_scope(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_ShortcutController_remove_shortcut(value instance_, value shortcut) {
  CAMLparam2(instance_, shortcut);
  gtk_shortcut_controller_remove_shortcut(GObject_val(instance_), GObject_val(shortcut));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ShortcutController_set_mnemonics_modifiers(value instance_, value modifiers) {
  CAMLparam2(instance_, modifiers);
  gtk_shortcut_controller_set_mnemonics_modifiers(GObject_val(instance_), Int_val(modifiers));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ShortcutController_set_scope(value instance_, value scope) {
  CAMLparam2(instance_, scope);
  gtk_shortcut_controller_set_scope(GObject_val(instance_), Int_val(scope));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ShortcutLabel_new(value accelerator) {
  CAMLparam1(accelerator);
  void * result = gtk_shortcut_label_new(String_val(accelerator));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ShortcutLabel_set_accelerator(value instance_, value accelerator) {
  CAMLparam2(instance_, accelerator);
  gtk_shortcut_label_set_accelerator(GObject_val(instance_), String_val(accelerator));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ShortcutLabel_set_disabled_text(value instance_, value disabled_text) {
  CAMLparam2(instance_, disabled_text);
  gtk_shortcut_label_set_disabled_text(GObject_val(instance_), String_val(disabled_text));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ShortcutTrigger_parse_string(value string) {
  CAMLparam1(string);
  void * result = gtk_shortcut_trigger_parse_string(String_val(string));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ShortcutTrigger_compare(value instance_, value trigger2) {
  CAMLparam2(instance_, trigger2);
  gint32 result = gtk_shortcut_trigger_compare(GObject_val(instance_), GObject_val(trigger2));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_ShortcutTrigger_equal(value instance_, value trigger2) {
  CAMLparam2(instance_, trigger2);
  gboolean result = gtk_shortcut_trigger_equal(GObject_val(instance_), GObject_val(trigger2));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ShortcutTrigger_hash(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_shortcut_trigger_hash(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

gboolean ml_Gtk_ShortcutsSection_signal_handler_change_current_page(GObject *instance_, gint32 object, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_long(object);
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_ShortcutsSection_signal_connect_change_current_page(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "change-current-page", ml_Gtk_ShortcutsSection_signal_handler_change_current_page, callback);
}

void ml_Gtk_ShortcutsWindow_signal_handler_close(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_ShortcutsWindow_signal_connect_close(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "close", ml_Gtk_ShortcutsWindow_signal_handler_close, callback);
}

void ml_Gtk_ShortcutsWindow_signal_handler_search(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_ShortcutsWindow_signal_connect_search(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "search", ml_Gtk_ShortcutsWindow_signal_handler_search, callback);
}

CAMLprim value ml_Gtk_SignalAction_new(value signal_name) {
  CAMLparam1(signal_name);
  void * result = gtk_signal_action_new(String_val(signal_name));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_SignalListItemFactory_new() {
  CAMLparam0();
  void * result = gtk_signal_list_item_factory_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

void ml_Gtk_SignalListItemFactory_signal_handler_bind(GObject *instance_, void * listitem, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(listitem));
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_SignalListItemFactory_signal_connect_bind(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "bind", ml_Gtk_SignalListItemFactory_signal_handler_bind, callback);
}

void ml_Gtk_SignalListItemFactory_signal_handler_setup(GObject *instance_, void * listitem, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(listitem));
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_SignalListItemFactory_signal_connect_setup(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "setup", ml_Gtk_SignalListItemFactory_signal_handler_setup, callback);
}

void ml_Gtk_SignalListItemFactory_signal_handler_teardown(GObject *instance_, void * listitem, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(listitem));
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_SignalListItemFactory_signal_connect_teardown(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "teardown", ml_Gtk_SignalListItemFactory_signal_handler_teardown, callback);
}

void ml_Gtk_SignalListItemFactory_signal_handler_unbind(GObject *instance_, void * listitem, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(listitem));
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_SignalListItemFactory_signal_connect_unbind(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "unbind", ml_Gtk_SignalListItemFactory_signal_handler_unbind, callback);
}

CAMLprim value ml_Gtk_SingleSelection_get_autoselect(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_single_selection_get_autoselect(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_SingleSelection_get_can_unselect(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_single_selection_get_can_unselect(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_SingleSelection_get_selected(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_single_selection_get_selected(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_SingleSelection_get_selected_item(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_single_selection_get_selected_item(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_SingleSelection_set_autoselect(value instance_, value autoselect) {
  CAMLparam2(instance_, autoselect);
  gtk_single_selection_set_autoselect(GObject_val(instance_), Bool_val(autoselect));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_SingleSelection_set_can_unselect(value instance_, value can_unselect) {
  CAMLparam2(instance_, can_unselect);
  gtk_single_selection_set_can_unselect(GObject_val(instance_), Bool_val(can_unselect));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_SingleSelection_set_selected(value instance_, value position) {
  CAMLparam2(instance_, position);
  gtk_single_selection_set_selected(GObject_val(instance_), Long_val(position));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_SizeGroup_new(value mode) {
  CAMLparam1(mode);
  void * result = gtk_size_group_new(Int_val(mode));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_SizeGroup_add_widget(value instance_, value widget) {
  CAMLparam2(instance_, widget);
  gtk_size_group_add_widget(GObject_val(instance_), GObject_val(widget));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_SizeGroup_get_mode(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_size_group_get_mode(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_SizeGroup_remove_widget(value instance_, value widget) {
  CAMLparam2(instance_, widget);
  gtk_size_group_remove_widget(GObject_val(instance_), GObject_val(widget));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_SizeGroup_set_mode(value instance_, value mode) {
  CAMLparam2(instance_, mode);
  gtk_size_group_set_mode(GObject_val(instance_), Int_val(mode));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_SliceListModel_get_offset(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_slice_list_model_get_offset(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_SliceListModel_get_size(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_slice_list_model_get_size(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_SliceListModel_set_offset(value instance_, value offset) {
  CAMLparam2(instance_, offset);
  gtk_slice_list_model_set_offset(GObject_val(instance_), Long_val(offset));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_SliceListModel_set_size(value instance_, value size) {
  CAMLparam2(instance_, size);
  gtk_slice_list_model_set_size(GObject_val(instance_), Long_val(size));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Snapshot_new() {
  CAMLparam0();
  void * result = gtk_snapshot_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Snapshot_gl_shader_pop_texture(value instance_) {
  CAMLparam1(instance_);
  gtk_snapshot_gl_shader_pop_texture(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Snapshot_pop(value instance_) {
  CAMLparam1(instance_);
  gtk_snapshot_pop(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Snapshot_restore(value instance_) {
  CAMLparam1(instance_);
  gtk_snapshot_restore(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Snapshot_save(value instance_) {
  CAMLparam1(instance_);
  gtk_snapshot_save(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_SortListModel_get_incremental(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_sort_list_model_get_incremental(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_SortListModel_get_pending(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_sort_list_model_get_pending(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_SortListModel_get_sorter(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_sort_list_model_get_sorter(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_SortListModel_set_incremental(value instance_, value incremental) {
  CAMLparam2(instance_, incremental);
  gtk_sort_list_model_set_incremental(GObject_val(instance_), Bool_val(incremental));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_SortListModel_set_sorter(value instance_, value sorter) {
  CAMLparam2(instance_, sorter);
  gtk_sort_list_model_set_sorter(GObject_val(instance_), GObject_val(sorter));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Sorter_changed(value instance_, value change) {
  CAMLparam2(instance_, change);
  gtk_sorter_changed(GObject_val(instance_), Int_val(change));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Sorter_compare(value instance_, value item1, value item2) {
  CAMLparam3(instance_, item1, item2);
  int result = gtk_sorter_compare(GObject_val(instance_), GObject_val(item1), GObject_val(item2));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_Sorter_get_order(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_sorter_get_order(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

void ml_Gtk_Sorter_signal_handler_changed(GObject *instance_, int change, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_int(change);
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Sorter_signal_connect_changed(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "changed", ml_Gtk_Sorter_signal_handler_changed, callback);
}

CAMLprim value ml_Gtk_SpinButton_get_adjustment(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_spin_button_get_adjustment(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_SpinButton_get_digits(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_spin_button_get_digits(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_SpinButton_get_numeric(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_spin_button_get_numeric(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_SpinButton_get_snap_to_ticks(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_spin_button_get_snap_to_ticks(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_SpinButton_get_update_policy(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_spin_button_get_update_policy(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_SpinButton_get_value_as_int(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_spin_button_get_value_as_int(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_SpinButton_get_wrap(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_spin_button_get_wrap(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_SpinButton_set_adjustment(value instance_, value adjustment) {
  CAMLparam2(instance_, adjustment);
  gtk_spin_button_set_adjustment(GObject_val(instance_), GObject_val(adjustment));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_SpinButton_set_digits(value instance_, value digits) {
  CAMLparam2(instance_, digits);
  gtk_spin_button_set_digits(GObject_val(instance_), Long_val(digits));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_SpinButton_set_numeric(value instance_, value numeric) {
  CAMLparam2(instance_, numeric);
  gtk_spin_button_set_numeric(GObject_val(instance_), Bool_val(numeric));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_SpinButton_set_snap_to_ticks(value instance_, value snap_to_ticks) {
  CAMLparam2(instance_, snap_to_ticks);
  gtk_spin_button_set_snap_to_ticks(GObject_val(instance_), Bool_val(snap_to_ticks));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_SpinButton_set_update_policy(value instance_, value policy) {
  CAMLparam2(instance_, policy);
  gtk_spin_button_set_update_policy(GObject_val(instance_), Int_val(policy));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_SpinButton_set_wrap(value instance_, value wrap) {
  CAMLparam2(instance_, wrap);
  gtk_spin_button_set_wrap(GObject_val(instance_), Bool_val(wrap));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_SpinButton_update(value instance_) {
  CAMLparam1(instance_);
  gtk_spin_button_update(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

void ml_Gtk_SpinButton_signal_handler_change_value(GObject *instance_, int scroll, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_int(scroll);
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_SpinButton_signal_connect_change_value(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "change-value", ml_Gtk_SpinButton_signal_handler_change_value, callback);
}

gboolean ml_Gtk_SpinButton_signal_handler_output(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_SpinButton_signal_connect_output(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "output", ml_Gtk_SpinButton_signal_handler_output, callback);
}

void ml_Gtk_SpinButton_signal_handler_value_changed(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_SpinButton_signal_connect_value_changed(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "value-changed", ml_Gtk_SpinButton_signal_handler_value_changed, callback);
}

void ml_Gtk_SpinButton_signal_handler_wrapped(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_SpinButton_signal_connect_wrapped(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "wrapped", ml_Gtk_SpinButton_signal_handler_wrapped, callback);
}

CAMLprim value ml_Gtk_Spinner_new() {
  CAMLparam0();
  void * result = gtk_spinner_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Spinner_get_spinning(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_spinner_get_spinning(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Spinner_set_spinning(value instance_, value spinning) {
  CAMLparam2(instance_, spinning);
  gtk_spinner_set_spinning(GObject_val(instance_), Bool_val(spinning));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Spinner_start(value instance_) {
  CAMLparam1(instance_);
  gtk_spinner_start(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Spinner_stop(value instance_) {
  CAMLparam1(instance_);
  gtk_spinner_stop(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Stack_new() {
  CAMLparam0();
  void * result = gtk_stack_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Stack_add_child(value instance_, value child) {
  CAMLparam2(instance_, child);
  void * result = gtk_stack_add_child(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Stack_add_named(value instance_, value child, value name) {
  CAMLparam3(instance_, child, name);
  void * result = gtk_stack_add_named(GObject_val(instance_), GObject_val(child), String_val(name));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Stack_add_titled(value instance_, value child, value name, value title) {
  CAMLparam4(instance_, child, name, title);
  void * result = gtk_stack_add_titled(GObject_val(instance_), GObject_val(child), String_val(name), String_val(title));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Stack_get_child_by_name(value instance_, value name) {
  CAMLparam2(instance_, name);
  void * result = gtk_stack_get_child_by_name(GObject_val(instance_), String_val(name));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Stack_get_hhomogeneous(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_stack_get_hhomogeneous(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Stack_get_interpolate_size(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_stack_get_interpolate_size(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Stack_get_page(value instance_, value child) {
  CAMLparam2(instance_, child);
  void * result = gtk_stack_get_page(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Stack_get_transition_duration(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_stack_get_transition_duration(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Stack_get_transition_running(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_stack_get_transition_running(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Stack_get_transition_type(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_stack_get_transition_type(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_Stack_get_vhomogeneous(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_stack_get_vhomogeneous(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Stack_get_visible_child(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_stack_get_visible_child(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Stack_remove(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_stack_remove(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Stack_set_hhomogeneous(value instance_, value hhomogeneous) {
  CAMLparam2(instance_, hhomogeneous);
  gtk_stack_set_hhomogeneous(GObject_val(instance_), Bool_val(hhomogeneous));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Stack_set_interpolate_size(value instance_, value interpolate_size) {
  CAMLparam2(instance_, interpolate_size);
  gtk_stack_set_interpolate_size(GObject_val(instance_), Bool_val(interpolate_size));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Stack_set_transition_duration(value instance_, value duration) {
  CAMLparam2(instance_, duration);
  gtk_stack_set_transition_duration(GObject_val(instance_), Long_val(duration));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Stack_set_transition_type(value instance_, value transition) {
  CAMLparam2(instance_, transition);
  gtk_stack_set_transition_type(GObject_val(instance_), Int_val(transition));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Stack_set_vhomogeneous(value instance_, value vhomogeneous) {
  CAMLparam2(instance_, vhomogeneous);
  gtk_stack_set_vhomogeneous(GObject_val(instance_), Bool_val(vhomogeneous));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Stack_set_visible_child(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_stack_set_visible_child(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Stack_set_visible_child_full(value instance_, value name, value transition) {
  CAMLparam3(instance_, name, transition);
  gtk_stack_set_visible_child_full(GObject_val(instance_), String_val(name), Int_val(transition));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Stack_set_visible_child_name(value instance_, value name) {
  CAMLparam2(instance_, name);
  gtk_stack_set_visible_child_name(GObject_val(instance_), String_val(name));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_StackPage_get_child(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_stack_page_get_child(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_StackPage_get_needs_attention(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_stack_page_get_needs_attention(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_StackPage_get_use_underline(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_stack_page_get_use_underline(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_StackPage_get_visible(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_stack_page_get_visible(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_StackPage_set_icon_name(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_stack_page_set_icon_name(GObject_val(instance_), String_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_StackPage_set_name(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_stack_page_set_name(GObject_val(instance_), String_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_StackPage_set_needs_attention(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_stack_page_set_needs_attention(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_StackPage_set_title(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_stack_page_set_title(GObject_val(instance_), String_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_StackPage_set_use_underline(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_stack_page_set_use_underline(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_StackPage_set_visible(value instance_, value visible) {
  CAMLparam2(instance_, visible);
  gtk_stack_page_set_visible(GObject_val(instance_), Bool_val(visible));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_StackSidebar_new() {
  CAMLparam0();
  void * result = gtk_stack_sidebar_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_StackSidebar_get_stack(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_stack_sidebar_get_stack(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_StackSidebar_set_stack(value instance_, value stack) {
  CAMLparam2(instance_, stack);
  gtk_stack_sidebar_set_stack(GObject_val(instance_), GObject_val(stack));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_StackSwitcher_new() {
  CAMLparam0();
  void * result = gtk_stack_switcher_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_StackSwitcher_get_stack(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_stack_switcher_get_stack(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_StackSwitcher_set_stack(value instance_, value stack) {
  CAMLparam2(instance_, stack);
  gtk_stack_switcher_set_stack(GObject_val(instance_), GObject_val(stack));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Statusbar_new() {
  CAMLparam0();
  void * result = gtk_statusbar_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Statusbar_get_context_id(value instance_, value context_description) {
  CAMLparam2(instance_, context_description);
  guint32 result = gtk_statusbar_get_context_id(GObject_val(instance_), String_val(context_description));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Statusbar_pop(value instance_, value context_id) {
  CAMLparam2(instance_, context_id);
  gtk_statusbar_pop(GObject_val(instance_), Long_val(context_id));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Statusbar_push(value instance_, value context_id, value text) {
  CAMLparam3(instance_, context_id, text);
  guint32 result = gtk_statusbar_push(GObject_val(instance_), Long_val(context_id), String_val(text));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Statusbar_remove(value instance_, value context_id, value message_id) {
  CAMLparam3(instance_, context_id, message_id);
  gtk_statusbar_remove(GObject_val(instance_), Long_val(context_id), Long_val(message_id));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Statusbar_remove_all(value instance_, value context_id) {
  CAMLparam2(instance_, context_id);
  gtk_statusbar_remove_all(GObject_val(instance_), Long_val(context_id));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_StringFilter_get_ignore_case(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_string_filter_get_ignore_case(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_StringFilter_get_match_mode(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_string_filter_get_match_mode(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_StringFilter_set_ignore_case(value instance_, value ignore_case) {
  CAMLparam2(instance_, ignore_case);
  gtk_string_filter_set_ignore_case(GObject_val(instance_), Bool_val(ignore_case));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_StringFilter_set_match_mode(value instance_, value mode) {
  CAMLparam2(instance_, mode);
  gtk_string_filter_set_match_mode(GObject_val(instance_), Int_val(mode));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_StringFilter_set_search(value instance_, value search) {
  CAMLparam2(instance_, search);
  gtk_string_filter_set_search(GObject_val(instance_), String_val(search));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_StringList_append(value instance_, value string) {
  CAMLparam2(instance_, string);
  gtk_string_list_append(GObject_val(instance_), String_val(string));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_StringList_remove(value instance_, value position) {
  CAMLparam2(instance_, position);
  gtk_string_list_remove(GObject_val(instance_), Long_val(position));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_StringObject_new(value string) {
  CAMLparam1(string);
  void * result = gtk_string_object_new(String_val(string));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_StringSorter_get_ignore_case(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_string_sorter_get_ignore_case(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_StringSorter_set_ignore_case(value instance_, value ignore_case) {
  CAMLparam2(instance_, ignore_case);
  gtk_string_sorter_set_ignore_case(GObject_val(instance_), Bool_val(ignore_case));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_StyleContext_add_class(value instance_, value class_name) {
  CAMLparam2(instance_, class_name);
  gtk_style_context_add_class(GObject_val(instance_), String_val(class_name));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_StyleContext_get_display(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_style_context_get_display(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_StyleContext_get_scale(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_style_context_get_scale(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_StyleContext_has_class(value instance_, value class_name) {
  CAMLparam2(instance_, class_name);
  gboolean result = gtk_style_context_has_class(GObject_val(instance_), String_val(class_name));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_StyleContext_remove_class(value instance_, value class_name) {
  CAMLparam2(instance_, class_name);
  gtk_style_context_remove_class(GObject_val(instance_), String_val(class_name));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_StyleContext_restore(value instance_) {
  CAMLparam1(instance_);
  gtk_style_context_restore(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_StyleContext_save(value instance_) {
  CAMLparam1(instance_);
  gtk_style_context_save(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_StyleContext_set_display(value instance_, value display) {
  CAMLparam2(instance_, display);
  gtk_style_context_set_display(GObject_val(instance_), GObject_val(display));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_StyleContext_set_scale(value instance_, value scale) {
  CAMLparam2(instance_, scale);
  gtk_style_context_set_scale(GObject_val(instance_), Long_val(scale));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_StyleContext_set_state(value instance_, value flags) {
  CAMLparam2(instance_, flags);
  gtk_style_context_set_state(GObject_val(instance_), Int_val(flags));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Switch_new() {
  CAMLparam0();
  void * result = gtk_switch_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Switch_get_active(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_switch_get_active(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Switch_get_state(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_switch_get_state(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Switch_set_active(value instance_, value is_active) {
  CAMLparam2(instance_, is_active);
  gtk_switch_set_active(GObject_val(instance_), Bool_val(is_active));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Switch_set_state(value instance_, value state) {
  CAMLparam2(instance_, state);
  gtk_switch_set_state(GObject_val(instance_), Bool_val(state));
  CAMLreturn(Val_unit);
}

void ml_Gtk_Switch_signal_handler_activate(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Switch_signal_connect_activate(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "activate", ml_Gtk_Switch_signal_handler_activate, callback);
}

gboolean ml_Gtk_Switch_signal_handler_state_set(GObject *instance_, gboolean state, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = (state ? Val_true : Val_false);
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_Switch_signal_connect_state_set(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "state-set", ml_Gtk_Switch_signal_handler_state_set, callback);
}

CAMLprim value ml_Gtk_Text_new() {
  CAMLparam0();
  void * result = gtk_text_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Text_new_with_buffer(value buffer) {
  CAMLparam1(buffer);
  void * result = gtk_text_new_with_buffer(GObject_val(buffer));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Text_get_activates_default(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_text_get_activates_default(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Text_get_buffer(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_text_get_buffer(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Text_get_enable_emoji_completion(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_text_get_enable_emoji_completion(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Text_get_extra_menu(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_text_get_extra_menu(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Text_get_input_purpose(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_text_get_input_purpose(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_Text_get_max_length(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_text_get_max_length(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Text_get_overwrite_mode(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_text_get_overwrite_mode(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Text_get_propagate_text_width(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_text_get_propagate_text_width(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Text_get_truncate_multiline(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_text_get_truncate_multiline(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Text_get_visibility(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_text_get_visibility(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Text_grab_focus_without_selecting(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_text_grab_focus_without_selecting(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Text_set_activates_default(value instance_, value activates) {
  CAMLparam2(instance_, activates);
  gtk_text_set_activates_default(GObject_val(instance_), Bool_val(activates));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Text_set_buffer(value instance_, value buffer) {
  CAMLparam2(instance_, buffer);
  gtk_text_set_buffer(GObject_val(instance_), GObject_val(buffer));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Text_set_enable_emoji_completion(value instance_, value enable_emoji_completion) {
  CAMLparam2(instance_, enable_emoji_completion);
  gtk_text_set_enable_emoji_completion(GObject_val(instance_), Bool_val(enable_emoji_completion));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Text_set_extra_menu(value instance_, value model) {
  CAMLparam2(instance_, model);
  gtk_text_set_extra_menu(GObject_val(instance_), GObject_val(model));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Text_set_input_hints(value instance_, value hints) {
  CAMLparam2(instance_, hints);
  gtk_text_set_input_hints(GObject_val(instance_), Int_val(hints));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Text_set_input_purpose(value instance_, value purpose) {
  CAMLparam2(instance_, purpose);
  gtk_text_set_input_purpose(GObject_val(instance_), Int_val(purpose));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Text_set_max_length(value instance_, value length) {
  CAMLparam2(instance_, length);
  gtk_text_set_max_length(GObject_val(instance_), Long_val(length));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Text_set_overwrite_mode(value instance_, value overwrite) {
  CAMLparam2(instance_, overwrite);
  gtk_text_set_overwrite_mode(GObject_val(instance_), Bool_val(overwrite));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Text_set_placeholder_text(value instance_, value text) {
  CAMLparam2(instance_, text);
  gtk_text_set_placeholder_text(GObject_val(instance_), String_val(text));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Text_set_propagate_text_width(value instance_, value propagate_text_width) {
  CAMLparam2(instance_, propagate_text_width);
  gtk_text_set_propagate_text_width(GObject_val(instance_), Bool_val(propagate_text_width));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Text_set_truncate_multiline(value instance_, value truncate_multiline) {
  CAMLparam2(instance_, truncate_multiline);
  gtk_text_set_truncate_multiline(GObject_val(instance_), Bool_val(truncate_multiline));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Text_set_visibility(value instance_, value visible) {
  CAMLparam2(instance_, visible);
  gtk_text_set_visibility(GObject_val(instance_), Bool_val(visible));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Text_unset_invisible_char(value instance_) {
  CAMLparam1(instance_);
  gtk_text_unset_invisible_char(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

void ml_Gtk_Text_signal_handler_activate(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Text_signal_connect_activate(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "activate", ml_Gtk_Text_signal_handler_activate, callback);
}

void ml_Gtk_Text_signal_handler_backspace(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Text_signal_connect_backspace(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "backspace", ml_Gtk_Text_signal_handler_backspace, callback);
}

void ml_Gtk_Text_signal_handler_copy_clipboard(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Text_signal_connect_copy_clipboard(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "copy-clipboard", ml_Gtk_Text_signal_handler_copy_clipboard, callback);
}

void ml_Gtk_Text_signal_handler_cut_clipboard(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Text_signal_connect_cut_clipboard(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "cut-clipboard", ml_Gtk_Text_signal_handler_cut_clipboard, callback);
}

void ml_Gtk_Text_signal_handler_delete_from_cursor(GObject *instance_, int type, gint32 count, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 2);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_int(type);
  args[1] = Val_long(count);
  ;caml_callbackN(*callbackCell, 2, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Text_signal_connect_delete_from_cursor(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "delete-from-cursor", ml_Gtk_Text_signal_handler_delete_from_cursor, callback);
}

void ml_Gtk_Text_signal_handler_insert_emoji(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Text_signal_connect_insert_emoji(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "insert-emoji", ml_Gtk_Text_signal_handler_insert_emoji, callback);
}

void ml_Gtk_Text_signal_handler_move_cursor(GObject *instance_, int step, gint32 count, gboolean extend, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 3);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_int(step);
  args[1] = Val_long(count);
  args[2] = (extend ? Val_true : Val_false);
  ;caml_callbackN(*callbackCell, 3, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Text_signal_connect_move_cursor(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "move-cursor", ml_Gtk_Text_signal_handler_move_cursor, callback);
}

void ml_Gtk_Text_signal_handler_paste_clipboard(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Text_signal_connect_paste_clipboard(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "paste-clipboard", ml_Gtk_Text_signal_handler_paste_clipboard, callback);
}

void ml_Gtk_Text_signal_handler_toggle_overwrite(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Text_signal_connect_toggle_overwrite(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "toggle-overwrite", ml_Gtk_Text_signal_handler_toggle_overwrite, callback);
}

CAMLprim value ml_Gtk_TextBuffer_new(value table) {
  CAMLparam1(table);
  void * result = gtk_text_buffer_new(GObject_val(table));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TextBuffer_add_selection_clipboard(value instance_, value clipboard) {
  CAMLparam2(instance_, clipboard);
  gtk_text_buffer_add_selection_clipboard(GObject_val(instance_), GObject_val(clipboard));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextBuffer_begin_irreversible_action(value instance_) {
  CAMLparam1(instance_);
  gtk_text_buffer_begin_irreversible_action(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextBuffer_begin_user_action(value instance_) {
  CAMLparam1(instance_);
  gtk_text_buffer_begin_user_action(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextBuffer_copy_clipboard(value instance_, value clipboard) {
  CAMLparam2(instance_, clipboard);
  gtk_text_buffer_copy_clipboard(GObject_val(instance_), GObject_val(clipboard));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextBuffer_cut_clipboard(value instance_, value clipboard, value default_editable) {
  CAMLparam3(instance_, clipboard, default_editable);
  gtk_text_buffer_cut_clipboard(GObject_val(instance_), GObject_val(clipboard), Bool_val(default_editable));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextBuffer_delete_mark(value instance_, value mark) {
  CAMLparam2(instance_, mark);
  gtk_text_buffer_delete_mark(GObject_val(instance_), GObject_val(mark));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextBuffer_delete_mark_by_name(value instance_, value name) {
  CAMLparam2(instance_, name);
  gtk_text_buffer_delete_mark_by_name(GObject_val(instance_), String_val(name));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextBuffer_delete_selection(value instance_, value interactive, value default_editable) {
  CAMLparam3(instance_, interactive, default_editable);
  gboolean result = gtk_text_buffer_delete_selection(GObject_val(instance_), Bool_val(interactive), Bool_val(default_editable));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TextBuffer_end_irreversible_action(value instance_) {
  CAMLparam1(instance_);
  gtk_text_buffer_end_irreversible_action(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextBuffer_end_user_action(value instance_) {
  CAMLparam1(instance_);
  gtk_text_buffer_end_user_action(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextBuffer_get_can_redo(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_text_buffer_get_can_redo(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TextBuffer_get_can_undo(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_text_buffer_get_can_undo(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TextBuffer_get_char_count(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_text_buffer_get_char_count(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_TextBuffer_get_enable_undo(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_text_buffer_get_enable_undo(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TextBuffer_get_has_selection(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_text_buffer_get_has_selection(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TextBuffer_get_insert(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_text_buffer_get_insert(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TextBuffer_get_line_count(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_text_buffer_get_line_count(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_TextBuffer_get_mark(value instance_, value name) {
  CAMLparam2(instance_, name);
  void * result = gtk_text_buffer_get_mark(GObject_val(instance_), String_val(name));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TextBuffer_get_max_undo_levels(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_text_buffer_get_max_undo_levels(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_TextBuffer_get_modified(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_text_buffer_get_modified(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TextBuffer_get_selection_bound(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_text_buffer_get_selection_bound(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TextBuffer_get_selection_content(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_text_buffer_get_selection_content(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TextBuffer_get_tag_table(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_text_buffer_get_tag_table(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TextBuffer_insert_at_cursor(value instance_, value text, value len) {
  CAMLparam3(instance_, text, len);
  gtk_text_buffer_insert_at_cursor(GObject_val(instance_), String_val(text), Long_val(len));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextBuffer_insert_interactive_at_cursor(value instance_, value text, value len, value default_editable) {
  CAMLparam4(instance_, text, len, default_editable);
  gboolean result = gtk_text_buffer_insert_interactive_at_cursor(GObject_val(instance_), String_val(text), Long_val(len), Bool_val(default_editable));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TextBuffer_redo(value instance_) {
  CAMLparam1(instance_);
  gtk_text_buffer_redo(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextBuffer_remove_selection_clipboard(value instance_, value clipboard) {
  CAMLparam2(instance_, clipboard);
  gtk_text_buffer_remove_selection_clipboard(GObject_val(instance_), GObject_val(clipboard));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextBuffer_set_enable_undo(value instance_, value enable_undo) {
  CAMLparam2(instance_, enable_undo);
  gtk_text_buffer_set_enable_undo(GObject_val(instance_), Bool_val(enable_undo));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextBuffer_set_max_undo_levels(value instance_, value max_undo_levels) {
  CAMLparam2(instance_, max_undo_levels);
  gtk_text_buffer_set_max_undo_levels(GObject_val(instance_), Long_val(max_undo_levels));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextBuffer_set_modified(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_text_buffer_set_modified(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextBuffer_set_text(value instance_, value text, value len) {
  CAMLparam3(instance_, text, len);
  gtk_text_buffer_set_text(GObject_val(instance_), String_val(text), Long_val(len));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextBuffer_undo(value instance_) {
  CAMLparam1(instance_);
  gtk_text_buffer_undo(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

void ml_Gtk_TextBuffer_signal_handler_begin_user_action(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_TextBuffer_signal_connect_begin_user_action(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "begin-user-action", ml_Gtk_TextBuffer_signal_handler_begin_user_action, callback);
}

void ml_Gtk_TextBuffer_signal_handler_changed(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_TextBuffer_signal_connect_changed(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "changed", ml_Gtk_TextBuffer_signal_handler_changed, callback);
}

void ml_Gtk_TextBuffer_signal_handler_end_user_action(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_TextBuffer_signal_connect_end_user_action(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "end-user-action", ml_Gtk_TextBuffer_signal_handler_end_user_action, callback);
}

void ml_Gtk_TextBuffer_signal_handler_mark_deleted(GObject *instance_, void * mark, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(mark));
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_TextBuffer_signal_connect_mark_deleted(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "mark-deleted", ml_Gtk_TextBuffer_signal_handler_mark_deleted, callback);
}

void ml_Gtk_TextBuffer_signal_handler_modified_changed(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_TextBuffer_signal_connect_modified_changed(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "modified-changed", ml_Gtk_TextBuffer_signal_handler_modified_changed, callback);
}

void ml_Gtk_TextBuffer_signal_handler_paste_done(GObject *instance_, void * clipboard, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(clipboard));
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_TextBuffer_signal_connect_paste_done(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "paste-done", ml_Gtk_TextBuffer_signal_handler_paste_done, callback);
}

void ml_Gtk_TextBuffer_signal_handler_redo(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_TextBuffer_signal_connect_redo(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "redo", ml_Gtk_TextBuffer_signal_handler_redo, callback);
}

void ml_Gtk_TextBuffer_signal_handler_undo(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_TextBuffer_signal_connect_undo(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "undo", ml_Gtk_TextBuffer_signal_handler_undo, callback);
}

CAMLprim value ml_Gtk_TextChildAnchor_new() {
  CAMLparam0();
  void * result = gtk_text_child_anchor_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TextChildAnchor_new_with_replacement(value character) {
  CAMLparam1(character);
  void * result = gtk_text_child_anchor_new_with_replacement(String_val(character));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TextChildAnchor_get_deleted(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_text_child_anchor_get_deleted(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TextMark_new(value name, value left_gravity) {
  CAMLparam2(name, left_gravity);
  void * result = gtk_text_mark_new(String_val(name), Bool_val(left_gravity));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TextMark_get_buffer(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_text_mark_get_buffer(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TextMark_get_deleted(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_text_mark_get_deleted(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TextMark_get_left_gravity(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_text_mark_get_left_gravity(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TextMark_get_visible(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_text_mark_get_visible(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TextMark_set_visible(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_text_mark_set_visible(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextTag_new(value name) {
  CAMLparam1(name);
  void * result = gtk_text_tag_new(String_val(name));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TextTag_changed(value instance_, value size_changed) {
  CAMLparam2(instance_, size_changed);
  gtk_text_tag_changed(GObject_val(instance_), Bool_val(size_changed));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextTag_get_priority(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_text_tag_get_priority(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_TextTag_set_priority(value instance_, value priority) {
  CAMLparam2(instance_, priority);
  gtk_text_tag_set_priority(GObject_val(instance_), Long_val(priority));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextTagTable_new() {
  CAMLparam0();
  void * result = gtk_text_tag_table_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TextTagTable_add(value instance_, value tag) {
  CAMLparam2(instance_, tag);
  gboolean result = gtk_text_tag_table_add(GObject_val(instance_), GObject_val(tag));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TextTagTable_get_size(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_text_tag_table_get_size(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_TextTagTable_lookup(value instance_, value name) {
  CAMLparam2(instance_, name);
  void * result = gtk_text_tag_table_lookup(GObject_val(instance_), String_val(name));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TextTagTable_remove(value instance_, value tag) {
  CAMLparam2(instance_, tag);
  gtk_text_tag_table_remove(GObject_val(instance_), GObject_val(tag));
  CAMLreturn(Val_unit);
}

void ml_Gtk_TextTagTable_signal_handler_tag_added(GObject *instance_, void * tag, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(tag));
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_TextTagTable_signal_connect_tag_added(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "tag-added", ml_Gtk_TextTagTable_signal_handler_tag_added, callback);
}

void ml_Gtk_TextTagTable_signal_handler_tag_changed(GObject *instance_, void * tag, gboolean size_changed, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 2);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(tag));
  args[1] = (size_changed ? Val_true : Val_false);
  ;caml_callbackN(*callbackCell, 2, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_TextTagTable_signal_connect_tag_changed(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "tag-changed", ml_Gtk_TextTagTable_signal_handler_tag_changed, callback);
}

void ml_Gtk_TextTagTable_signal_handler_tag_removed(GObject *instance_, void * tag, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_GObject((void *)(tag));
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_TextTagTable_signal_connect_tag_removed(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "tag-removed", ml_Gtk_TextTagTable_signal_handler_tag_removed, callback);
}

CAMLprim value ml_Gtk_TextView_new() {
  CAMLparam0();
  void * result = gtk_text_view_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TextView_new_with_buffer(value buffer) {
  CAMLparam1(buffer);
  void * result = gtk_text_view_new_with_buffer(GObject_val(buffer));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TextView_add_child_at_anchor(value instance_, value child, value anchor) {
  CAMLparam3(instance_, child, anchor);
  gtk_text_view_add_child_at_anchor(GObject_val(instance_), GObject_val(child), GObject_val(anchor));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextView_add_overlay(value instance_, value child, value xpos, value ypos) {
  CAMLparam4(instance_, child, xpos, ypos);
  gtk_text_view_add_overlay(GObject_val(instance_), GObject_val(child), Long_val(xpos), Long_val(ypos));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextView_get_accepts_tab(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_text_view_get_accepts_tab(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TextView_get_bottom_margin(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_text_view_get_bottom_margin(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_TextView_get_buffer(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_text_view_get_buffer(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TextView_get_cursor_visible(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_text_view_get_cursor_visible(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TextView_get_editable(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_text_view_get_editable(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TextView_get_extra_menu(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_text_view_get_extra_menu(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TextView_get_gutter(value instance_, value win) {
  CAMLparam2(instance_, win);
  void * result = gtk_text_view_get_gutter(GObject_val(instance_), Int_val(win));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TextView_get_indent(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_text_view_get_indent(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_TextView_get_input_purpose(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_text_view_get_input_purpose(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_TextView_get_justification(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_text_view_get_justification(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_TextView_get_left_margin(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_text_view_get_left_margin(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_TextView_get_monospace(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_text_view_get_monospace(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TextView_get_overwrite(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_text_view_get_overwrite(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TextView_get_pixels_above_lines(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_text_view_get_pixels_above_lines(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_TextView_get_pixels_below_lines(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_text_view_get_pixels_below_lines(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_TextView_get_pixels_inside_wrap(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_text_view_get_pixels_inside_wrap(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_TextView_get_right_margin(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_text_view_get_right_margin(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_TextView_get_top_margin(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_text_view_get_top_margin(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_TextView_get_wrap_mode(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_text_view_get_wrap_mode(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_TextView_move_mark_onscreen(value instance_, value mark) {
  CAMLparam2(instance_, mark);
  gboolean result = gtk_text_view_move_mark_onscreen(GObject_val(instance_), GObject_val(mark));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TextView_move_overlay(value instance_, value child, value xpos, value ypos) {
  CAMLparam4(instance_, child, xpos, ypos);
  gtk_text_view_move_overlay(GObject_val(instance_), GObject_val(child), Long_val(xpos), Long_val(ypos));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextView_place_cursor_onscreen(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_text_view_place_cursor_onscreen(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TextView_remove(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_text_view_remove(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextView_reset_cursor_blink(value instance_) {
  CAMLparam1(instance_);
  gtk_text_view_reset_cursor_blink(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextView_reset_im_context(value instance_) {
  CAMLparam1(instance_);
  gtk_text_view_reset_im_context(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextView_scroll_mark_onscreen(value instance_, value mark) {
  CAMLparam2(instance_, mark);
  gtk_text_view_scroll_mark_onscreen(GObject_val(instance_), GObject_val(mark));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextView_set_accepts_tab(value instance_, value accepts_tab) {
  CAMLparam2(instance_, accepts_tab);
  gtk_text_view_set_accepts_tab(GObject_val(instance_), Bool_val(accepts_tab));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextView_set_bottom_margin(value instance_, value bottom_margin) {
  CAMLparam2(instance_, bottom_margin);
  gtk_text_view_set_bottom_margin(GObject_val(instance_), Long_val(bottom_margin));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextView_set_buffer(value instance_, value buffer) {
  CAMLparam2(instance_, buffer);
  gtk_text_view_set_buffer(GObject_val(instance_), GObject_val(buffer));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextView_set_cursor_visible(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_text_view_set_cursor_visible(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextView_set_editable(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_text_view_set_editable(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextView_set_extra_menu(value instance_, value model) {
  CAMLparam2(instance_, model);
  gtk_text_view_set_extra_menu(GObject_val(instance_), GObject_val(model));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextView_set_gutter(value instance_, value win, value widget) {
  CAMLparam3(instance_, win, widget);
  gtk_text_view_set_gutter(GObject_val(instance_), Int_val(win), GObject_val(widget));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextView_set_indent(value instance_, value indent) {
  CAMLparam2(instance_, indent);
  gtk_text_view_set_indent(GObject_val(instance_), Long_val(indent));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextView_set_input_hints(value instance_, value hints) {
  CAMLparam2(instance_, hints);
  gtk_text_view_set_input_hints(GObject_val(instance_), Int_val(hints));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextView_set_input_purpose(value instance_, value purpose) {
  CAMLparam2(instance_, purpose);
  gtk_text_view_set_input_purpose(GObject_val(instance_), Int_val(purpose));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextView_set_justification(value instance_, value justification) {
  CAMLparam2(instance_, justification);
  gtk_text_view_set_justification(GObject_val(instance_), Int_val(justification));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextView_set_left_margin(value instance_, value left_margin) {
  CAMLparam2(instance_, left_margin);
  gtk_text_view_set_left_margin(GObject_val(instance_), Long_val(left_margin));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextView_set_monospace(value instance_, value monospace) {
  CAMLparam2(instance_, monospace);
  gtk_text_view_set_monospace(GObject_val(instance_), Bool_val(monospace));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextView_set_overwrite(value instance_, value overwrite) {
  CAMLparam2(instance_, overwrite);
  gtk_text_view_set_overwrite(GObject_val(instance_), Bool_val(overwrite));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextView_set_pixels_above_lines(value instance_, value pixels_above_lines) {
  CAMLparam2(instance_, pixels_above_lines);
  gtk_text_view_set_pixels_above_lines(GObject_val(instance_), Long_val(pixels_above_lines));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextView_set_pixels_below_lines(value instance_, value pixels_below_lines) {
  CAMLparam2(instance_, pixels_below_lines);
  gtk_text_view_set_pixels_below_lines(GObject_val(instance_), Long_val(pixels_below_lines));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextView_set_pixels_inside_wrap(value instance_, value pixels_inside_wrap) {
  CAMLparam2(instance_, pixels_inside_wrap);
  gtk_text_view_set_pixels_inside_wrap(GObject_val(instance_), Long_val(pixels_inside_wrap));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextView_set_right_margin(value instance_, value right_margin) {
  CAMLparam2(instance_, right_margin);
  gtk_text_view_set_right_margin(GObject_val(instance_), Long_val(right_margin));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextView_set_top_margin(value instance_, value top_margin) {
  CAMLparam2(instance_, top_margin);
  gtk_text_view_set_top_margin(GObject_val(instance_), Long_val(top_margin));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TextView_set_wrap_mode(value instance_, value wrap_mode) {
  CAMLparam2(instance_, wrap_mode);
  gtk_text_view_set_wrap_mode(GObject_val(instance_), Int_val(wrap_mode));
  CAMLreturn(Val_unit);
}

void ml_Gtk_TextView_signal_handler_backspace(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_TextView_signal_connect_backspace(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "backspace", ml_Gtk_TextView_signal_handler_backspace, callback);
}

void ml_Gtk_TextView_signal_handler_copy_clipboard(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_TextView_signal_connect_copy_clipboard(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "copy-clipboard", ml_Gtk_TextView_signal_handler_copy_clipboard, callback);
}

void ml_Gtk_TextView_signal_handler_cut_clipboard(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_TextView_signal_connect_cut_clipboard(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "cut-clipboard", ml_Gtk_TextView_signal_handler_cut_clipboard, callback);
}

void ml_Gtk_TextView_signal_handler_delete_from_cursor(GObject *instance_, int type, gint32 count, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 2);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_int(type);
  args[1] = Val_long(count);
  ;caml_callbackN(*callbackCell, 2, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_TextView_signal_connect_delete_from_cursor(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "delete-from-cursor", ml_Gtk_TextView_signal_handler_delete_from_cursor, callback);
}

void ml_Gtk_TextView_signal_handler_insert_emoji(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_TextView_signal_connect_insert_emoji(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "insert-emoji", ml_Gtk_TextView_signal_handler_insert_emoji, callback);
}

void ml_Gtk_TextView_signal_handler_move_cursor(GObject *instance_, int step, gint32 count, gboolean extend_selection, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 3);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_int(step);
  args[1] = Val_long(count);
  args[2] = (extend_selection ? Val_true : Val_false);
  ;caml_callbackN(*callbackCell, 3, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_TextView_signal_connect_move_cursor(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "move-cursor", ml_Gtk_TextView_signal_handler_move_cursor, callback);
}

void ml_Gtk_TextView_signal_handler_move_viewport(GObject *instance_, int step, gint32 count, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 2);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_int(step);
  args[1] = Val_long(count);
  ;caml_callbackN(*callbackCell, 2, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_TextView_signal_connect_move_viewport(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "move-viewport", ml_Gtk_TextView_signal_handler_move_viewport, callback);
}

void ml_Gtk_TextView_signal_handler_paste_clipboard(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_TextView_signal_connect_paste_clipboard(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "paste-clipboard", ml_Gtk_TextView_signal_handler_paste_clipboard, callback);
}

void ml_Gtk_TextView_signal_handler_select_all(GObject *instance_, gboolean select, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = (select ? Val_true : Val_false);
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_TextView_signal_connect_select_all(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "select-all", ml_Gtk_TextView_signal_handler_select_all, callback);
}

void ml_Gtk_TextView_signal_handler_set_anchor(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_TextView_signal_connect_set_anchor(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "set-anchor", ml_Gtk_TextView_signal_handler_set_anchor, callback);
}

void ml_Gtk_TextView_signal_handler_toggle_cursor_visible(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_TextView_signal_connect_toggle_cursor_visible(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "toggle-cursor-visible", ml_Gtk_TextView_signal_handler_toggle_cursor_visible, callback);
}

void ml_Gtk_TextView_signal_handler_toggle_overwrite(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_TextView_signal_connect_toggle_overwrite(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "toggle-overwrite", ml_Gtk_TextView_signal_handler_toggle_overwrite, callback);
}

CAMLprim value ml_Gtk_ToggleButton_new() {
  CAMLparam0();
  void * result = gtk_toggle_button_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ToggleButton_new_with_label(value label) {
  CAMLparam1(label);
  void * result = gtk_toggle_button_new_with_label(String_val(label));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ToggleButton_new_with_mnemonic(value label) {
  CAMLparam1(label);
  void * result = gtk_toggle_button_new_with_mnemonic(String_val(label));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_ToggleButton_get_active(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_toggle_button_get_active(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_ToggleButton_set_active(value instance_, value is_active) {
  CAMLparam2(instance_, is_active);
  gtk_toggle_button_set_active(GObject_val(instance_), Bool_val(is_active));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ToggleButton_set_group(value instance_, value group) {
  CAMLparam2(instance_, group);
  gtk_toggle_button_set_group(GObject_val(instance_), GObject_val(group));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_ToggleButton_toggled(value instance_) {
  CAMLparam1(instance_);
  gtk_toggle_button_toggled(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

void ml_Gtk_ToggleButton_signal_handler_toggled(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_ToggleButton_signal_connect_toggled(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "toggled", ml_Gtk_ToggleButton_signal_handler_toggled, callback);
}

CAMLprim value ml_Gtk_Tooltip_set_custom(value instance_, value custom_widget) {
  CAMLparam2(instance_, custom_widget);
  gtk_tooltip_set_custom(GObject_val(instance_), GObject_val(custom_widget));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Tooltip_set_icon_from_icon_name(value instance_, value icon_name) {
  CAMLparam2(instance_, icon_name);
  gtk_tooltip_set_icon_from_icon_name(GObject_val(instance_), String_val(icon_name));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Tooltip_set_markup(value instance_, value markup) {
  CAMLparam2(instance_, markup);
  gtk_tooltip_set_markup(GObject_val(instance_), String_val(markup));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Tooltip_set_text(value instance_, value text) {
  CAMLparam2(instance_, text);
  gtk_tooltip_set_text(GObject_val(instance_), String_val(text));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeExpander_new() {
  CAMLparam0();
  void * result = gtk_tree_expander_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TreeExpander_get_child(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_tree_expander_get_child(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TreeExpander_get_indent_for_icon(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_tree_expander_get_indent_for_icon(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TreeExpander_get_item(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_tree_expander_get_item(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TreeExpander_get_list_row(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_tree_expander_get_list_row(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TreeExpander_set_child(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_tree_expander_set_child(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeExpander_set_indent_for_icon(value instance_, value indent_for_icon) {
  CAMLparam2(instance_, indent_for_icon);
  gtk_tree_expander_set_indent_for_icon(GObject_val(instance_), Bool_val(indent_for_icon));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeExpander_set_list_row(value instance_, value list_row) {
  CAMLparam2(instance_, list_row);
  gtk_tree_expander_set_list_row(GObject_val(instance_), GObject_val(list_row));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeListModel_get_autoexpand(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_tree_list_model_get_autoexpand(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TreeListModel_get_child_row(value instance_, value position) {
  CAMLparam2(instance_, position);
  void * result = gtk_tree_list_model_get_child_row(GObject_val(instance_), Long_val(position));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TreeListModel_get_passthrough(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_tree_list_model_get_passthrough(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TreeListModel_get_row(value instance_, value position) {
  CAMLparam2(instance_, position);
  void * result = gtk_tree_list_model_get_row(GObject_val(instance_), Long_val(position));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TreeListModel_set_autoexpand(value instance_, value autoexpand) {
  CAMLparam2(instance_, autoexpand);
  gtk_tree_list_model_set_autoexpand(GObject_val(instance_), Bool_val(autoexpand));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeListRow_get_child_row(value instance_, value position) {
  CAMLparam2(instance_, position);
  void * result = gtk_tree_list_row_get_child_row(GObject_val(instance_), Long_val(position));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TreeListRow_get_depth(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_tree_list_row_get_depth(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_TreeListRow_get_expanded(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_tree_list_row_get_expanded(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TreeListRow_get_item(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_tree_list_row_get_item(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TreeListRow_get_parent(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_tree_list_row_get_parent(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TreeListRow_get_position(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_tree_list_row_get_position(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_TreeListRow_is_expandable(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_tree_list_row_is_expandable(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TreeListRow_set_expanded(value instance_, value expanded) {
  CAMLparam2(instance_, expanded);
  gtk_tree_list_row_set_expanded(GObject_val(instance_), Bool_val(expanded));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeListRowSorter_get_sorter(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_tree_list_row_sorter_get_sorter(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TreeListRowSorter_set_sorter(value instance_, value sorter) {
  CAMLparam2(instance_, sorter);
  gtk_tree_list_row_sorter_set_sorter(GObject_val(instance_), GObject_val(sorter));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeModelFilter_clear_cache(value instance_) {
  CAMLparam1(instance_);
  gtk_tree_model_filter_clear_cache(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeModelFilter_refilter(value instance_) {
  CAMLparam1(instance_);
  gtk_tree_model_filter_refilter(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeModelFilter_set_visible_column(value instance_, value column) {
  CAMLparam2(instance_, column);
  gtk_tree_model_filter_set_visible_column(GObject_val(instance_), Long_val(column));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeModelSort_clear_cache(value instance_) {
  CAMLparam1(instance_);
  gtk_tree_model_sort_clear_cache(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeModelSort_reset_default_sort_func(value instance_) {
  CAMLparam1(instance_);
  gtk_tree_model_sort_reset_default_sort_func(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeSelection_count_selected_rows(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_tree_selection_count_selected_rows(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_TreeSelection_get_mode(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_tree_selection_get_mode(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_TreeSelection_get_tree_view(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_tree_selection_get_tree_view(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TreeSelection_select_all(value instance_) {
  CAMLparam1(instance_);
  gtk_tree_selection_select_all(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeSelection_set_mode(value instance_, value type) {
  CAMLparam2(instance_, type);
  gtk_tree_selection_set_mode(GObject_val(instance_), Int_val(type));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeSelection_unselect_all(value instance_) {
  CAMLparam1(instance_);
  gtk_tree_selection_unselect_all(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

void ml_Gtk_TreeSelection_signal_handler_changed(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_TreeSelection_signal_connect_changed(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "changed", ml_Gtk_TreeSelection_signal_handler_changed, callback);
}

CAMLprim value ml_Gtk_TreeStore_clear(value instance_) {
  CAMLparam1(instance_);
  gtk_tree_store_clear(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeView_new() {
  CAMLparam0();
  void * result = gtk_tree_view_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TreeView_append_column(value instance_, value column) {
  CAMLparam2(instance_, column);
  gint32 result = gtk_tree_view_append_column(GObject_val(instance_), GObject_val(column));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_TreeView_collapse_all(value instance_) {
  CAMLparam1(instance_);
  gtk_tree_view_collapse_all(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeView_columns_autosize(value instance_) {
  CAMLparam1(instance_);
  gtk_tree_view_columns_autosize(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeView_expand_all(value instance_) {
  CAMLparam1(instance_);
  gtk_tree_view_expand_all(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeView_get_activate_on_single_click(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_tree_view_get_activate_on_single_click(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TreeView_get_column(value instance_, value n) {
  CAMLparam2(instance_, n);
  void * result = gtk_tree_view_get_column(GObject_val(instance_), Long_val(n));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TreeView_get_enable_search(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_tree_view_get_enable_search(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TreeView_get_enable_tree_lines(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_tree_view_get_enable_tree_lines(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TreeView_get_expander_column(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_tree_view_get_expander_column(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TreeView_get_fixed_height_mode(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_tree_view_get_fixed_height_mode(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TreeView_get_grid_lines(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_tree_view_get_grid_lines(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_TreeView_get_headers_clickable(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_tree_view_get_headers_clickable(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TreeView_get_headers_visible(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_tree_view_get_headers_visible(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TreeView_get_hover_expand(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_tree_view_get_hover_expand(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TreeView_get_hover_selection(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_tree_view_get_hover_selection(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TreeView_get_level_indentation(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_tree_view_get_level_indentation(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_TreeView_get_n_columns(value instance_) {
  CAMLparam1(instance_);
  guint32 result = gtk_tree_view_get_n_columns(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_TreeView_get_reorderable(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_tree_view_get_reorderable(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TreeView_get_rubber_banding(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_tree_view_get_rubber_banding(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TreeView_get_search_column(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_tree_view_get_search_column(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_TreeView_get_selection(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_tree_view_get_selection(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TreeView_get_show_expanders(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_tree_view_get_show_expanders(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TreeView_get_tooltip_column(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_tree_view_get_tooltip_column(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_TreeView_insert_column(value instance_, value column, value position) {
  CAMLparam3(instance_, column, position);
  gint32 result = gtk_tree_view_insert_column(GObject_val(instance_), GObject_val(column), Long_val(position));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_TreeView_is_rubber_banding_active(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_tree_view_is_rubber_banding_active(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TreeView_move_column_after(value instance_, value column, value base_column) {
  CAMLparam3(instance_, column, base_column);
  gtk_tree_view_move_column_after(GObject_val(instance_), GObject_val(column), GObject_val(base_column));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeView_remove_column(value instance_, value column) {
  CAMLparam2(instance_, column);
  gint32 result = gtk_tree_view_remove_column(GObject_val(instance_), GObject_val(column));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_TreeView_scroll_to_point(value instance_, value tree_x, value tree_y) {
  CAMLparam3(instance_, tree_x, tree_y);
  gtk_tree_view_scroll_to_point(GObject_val(instance_), Long_val(tree_x), Long_val(tree_y));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeView_set_activate_on_single_click(value instance_, value single) {
  CAMLparam2(instance_, single);
  gtk_tree_view_set_activate_on_single_click(GObject_val(instance_), Bool_val(single));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeView_set_enable_search(value instance_, value enable_search) {
  CAMLparam2(instance_, enable_search);
  gtk_tree_view_set_enable_search(GObject_val(instance_), Bool_val(enable_search));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeView_set_enable_tree_lines(value instance_, value enabled) {
  CAMLparam2(instance_, enabled);
  gtk_tree_view_set_enable_tree_lines(GObject_val(instance_), Bool_val(enabled));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeView_set_expander_column(value instance_, value column) {
  CAMLparam2(instance_, column);
  gtk_tree_view_set_expander_column(GObject_val(instance_), GObject_val(column));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeView_set_fixed_height_mode(value instance_, value enable) {
  CAMLparam2(instance_, enable);
  gtk_tree_view_set_fixed_height_mode(GObject_val(instance_), Bool_val(enable));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeView_set_grid_lines(value instance_, value grid_lines) {
  CAMLparam2(instance_, grid_lines);
  gtk_tree_view_set_grid_lines(GObject_val(instance_), Int_val(grid_lines));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeView_set_headers_clickable(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_tree_view_set_headers_clickable(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeView_set_headers_visible(value instance_, value headers_visible) {
  CAMLparam2(instance_, headers_visible);
  gtk_tree_view_set_headers_visible(GObject_val(instance_), Bool_val(headers_visible));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeView_set_hover_expand(value instance_, value expand) {
  CAMLparam2(instance_, expand);
  gtk_tree_view_set_hover_expand(GObject_val(instance_), Bool_val(expand));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeView_set_hover_selection(value instance_, value hover) {
  CAMLparam2(instance_, hover);
  gtk_tree_view_set_hover_selection(GObject_val(instance_), Bool_val(hover));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeView_set_level_indentation(value instance_, value indentation) {
  CAMLparam2(instance_, indentation);
  gtk_tree_view_set_level_indentation(GObject_val(instance_), Long_val(indentation));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeView_set_reorderable(value instance_, value reorderable) {
  CAMLparam2(instance_, reorderable);
  gtk_tree_view_set_reorderable(GObject_val(instance_), Bool_val(reorderable));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeView_set_rubber_banding(value instance_, value enable) {
  CAMLparam2(instance_, enable);
  gtk_tree_view_set_rubber_banding(GObject_val(instance_), Bool_val(enable));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeView_set_search_column(value instance_, value column) {
  CAMLparam2(instance_, column);
  gtk_tree_view_set_search_column(GObject_val(instance_), Long_val(column));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeView_set_show_expanders(value instance_, value enabled) {
  CAMLparam2(instance_, enabled);
  gtk_tree_view_set_show_expanders(GObject_val(instance_), Bool_val(enabled));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeView_set_tooltip_column(value instance_, value column) {
  CAMLparam2(instance_, column);
  gtk_tree_view_set_tooltip_column(GObject_val(instance_), Long_val(column));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeView_unset_rows_drag_dest(value instance_) {
  CAMLparam1(instance_);
  gtk_tree_view_unset_rows_drag_dest(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeView_unset_rows_drag_source(value instance_) {
  CAMLparam1(instance_);
  gtk_tree_view_unset_rows_drag_source(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

void ml_Gtk_TreeView_signal_handler_columns_changed(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_TreeView_signal_connect_columns_changed(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "columns-changed", ml_Gtk_TreeView_signal_handler_columns_changed, callback);
}

void ml_Gtk_TreeView_signal_handler_cursor_changed(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_TreeView_signal_connect_cursor_changed(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "cursor-changed", ml_Gtk_TreeView_signal_handler_cursor_changed, callback);
}

gboolean ml_Gtk_TreeView_signal_handler_expand_collapse_cursor_row(GObject *instance_, gboolean object, gboolean p0, gboolean p1, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 3);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = (object ? Val_true : Val_false);
  args[1] = (p0 ? Val_true : Val_false);
  args[2] = (p1 ? Val_true : Val_false);
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 3, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_TreeView_signal_connect_expand_collapse_cursor_row(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "expand-collapse-cursor-row", ml_Gtk_TreeView_signal_handler_expand_collapse_cursor_row, callback);
}

gboolean ml_Gtk_TreeView_signal_handler_move_cursor(GObject *instance_, int step, gint32 direction, gboolean extend, gboolean modify, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 4);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_int(step);
  args[1] = Val_long(direction);
  args[2] = (extend ? Val_true : Val_false);
  args[3] = (modify ? Val_true : Val_false);
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 4, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_TreeView_signal_connect_move_cursor(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "move-cursor", ml_Gtk_TreeView_signal_handler_move_cursor, callback);
}

gboolean ml_Gtk_TreeView_signal_handler_select_all(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_TreeView_signal_connect_select_all(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "select-all", ml_Gtk_TreeView_signal_handler_select_all, callback);
}

gboolean ml_Gtk_TreeView_signal_handler_select_cursor_parent(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_TreeView_signal_connect_select_cursor_parent(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "select-cursor-parent", ml_Gtk_TreeView_signal_handler_select_cursor_parent, callback);
}

gboolean ml_Gtk_TreeView_signal_handler_select_cursor_row(GObject *instance_, gboolean object, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = (object ? Val_true : Val_false);
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_TreeView_signal_connect_select_cursor_row(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "select-cursor-row", ml_Gtk_TreeView_signal_handler_select_cursor_row, callback);
}

gboolean ml_Gtk_TreeView_signal_handler_start_interactive_search(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_TreeView_signal_connect_start_interactive_search(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "start-interactive-search", ml_Gtk_TreeView_signal_handler_start_interactive_search, callback);
}

gboolean ml_Gtk_TreeView_signal_handler_toggle_cursor_row(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_TreeView_signal_connect_toggle_cursor_row(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "toggle-cursor-row", ml_Gtk_TreeView_signal_handler_toggle_cursor_row, callback);
}

gboolean ml_Gtk_TreeView_signal_handler_unselect_all(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_TreeView_signal_connect_unselect_all(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "unselect-all", ml_Gtk_TreeView_signal_handler_unselect_all, callback);
}

CAMLprim value ml_Gtk_TreeViewColumn_new() {
  CAMLparam0();
  void * result = gtk_tree_view_column_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TreeViewColumn_new_with_area(value area) {
  CAMLparam1(area);
  void * result = gtk_tree_view_column_new_with_area(GObject_val(area));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TreeViewColumn_add_attribute(value instance_, value cell_renderer, value attribute, value column) {
  CAMLparam4(instance_, cell_renderer, attribute, column);
  gtk_tree_view_column_add_attribute(GObject_val(instance_), GObject_val(cell_renderer), String_val(attribute), Long_val(column));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeViewColumn_cell_is_visible(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_tree_view_column_cell_is_visible(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TreeViewColumn_clear(value instance_) {
  CAMLparam1(instance_);
  gtk_tree_view_column_clear(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeViewColumn_clear_attributes(value instance_, value cell_renderer) {
  CAMLparam2(instance_, cell_renderer);
  gtk_tree_view_column_clear_attributes(GObject_val(instance_), GObject_val(cell_renderer));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeViewColumn_clicked(value instance_) {
  CAMLparam1(instance_);
  gtk_tree_view_column_clicked(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeViewColumn_focus_cell(value instance_, value cell) {
  CAMLparam2(instance_, cell);
  gtk_tree_view_column_focus_cell(GObject_val(instance_), GObject_val(cell));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeViewColumn_get_button(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_tree_view_column_get_button(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TreeViewColumn_get_clickable(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_tree_view_column_get_clickable(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TreeViewColumn_get_expand(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_tree_view_column_get_expand(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TreeViewColumn_get_fixed_width(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_tree_view_column_get_fixed_width(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_TreeViewColumn_get_max_width(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_tree_view_column_get_max_width(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_TreeViewColumn_get_min_width(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_tree_view_column_get_min_width(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_TreeViewColumn_get_reorderable(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_tree_view_column_get_reorderable(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TreeViewColumn_get_resizable(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_tree_view_column_get_resizable(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TreeViewColumn_get_sizing(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_tree_view_column_get_sizing(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_TreeViewColumn_get_sort_column_id(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_tree_view_column_get_sort_column_id(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_TreeViewColumn_get_sort_indicator(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_tree_view_column_get_sort_indicator(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TreeViewColumn_get_sort_order(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_tree_view_column_get_sort_order(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_TreeViewColumn_get_spacing(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_tree_view_column_get_spacing(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_TreeViewColumn_get_tree_view(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_tree_view_column_get_tree_view(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TreeViewColumn_get_visible(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_tree_view_column_get_visible(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_TreeViewColumn_get_widget(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_tree_view_column_get_widget(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_TreeViewColumn_get_width(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_tree_view_column_get_width(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_TreeViewColumn_get_x_offset(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_tree_view_column_get_x_offset(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_TreeViewColumn_pack_end(value instance_, value cell, value expand) {
  CAMLparam3(instance_, cell, expand);
  gtk_tree_view_column_pack_end(GObject_val(instance_), GObject_val(cell), Bool_val(expand));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeViewColumn_pack_start(value instance_, value cell, value expand) {
  CAMLparam3(instance_, cell, expand);
  gtk_tree_view_column_pack_start(GObject_val(instance_), GObject_val(cell), Bool_val(expand));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeViewColumn_queue_resize(value instance_) {
  CAMLparam1(instance_);
  gtk_tree_view_column_queue_resize(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeViewColumn_set_clickable(value instance_, value clickable) {
  CAMLparam2(instance_, clickable);
  gtk_tree_view_column_set_clickable(GObject_val(instance_), Bool_val(clickable));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeViewColumn_set_expand(value instance_, value expand) {
  CAMLparam2(instance_, expand);
  gtk_tree_view_column_set_expand(GObject_val(instance_), Bool_val(expand));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeViewColumn_set_fixed_width(value instance_, value fixed_width) {
  CAMLparam2(instance_, fixed_width);
  gtk_tree_view_column_set_fixed_width(GObject_val(instance_), Long_val(fixed_width));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeViewColumn_set_max_width(value instance_, value max_width) {
  CAMLparam2(instance_, max_width);
  gtk_tree_view_column_set_max_width(GObject_val(instance_), Long_val(max_width));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeViewColumn_set_min_width(value instance_, value min_width) {
  CAMLparam2(instance_, min_width);
  gtk_tree_view_column_set_min_width(GObject_val(instance_), Long_val(min_width));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeViewColumn_set_reorderable(value instance_, value reorderable) {
  CAMLparam2(instance_, reorderable);
  gtk_tree_view_column_set_reorderable(GObject_val(instance_), Bool_val(reorderable));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeViewColumn_set_resizable(value instance_, value resizable) {
  CAMLparam2(instance_, resizable);
  gtk_tree_view_column_set_resizable(GObject_val(instance_), Bool_val(resizable));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeViewColumn_set_sizing(value instance_, value type) {
  CAMLparam2(instance_, type);
  gtk_tree_view_column_set_sizing(GObject_val(instance_), Int_val(type));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeViewColumn_set_sort_column_id(value instance_, value sort_column_id) {
  CAMLparam2(instance_, sort_column_id);
  gtk_tree_view_column_set_sort_column_id(GObject_val(instance_), Long_val(sort_column_id));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeViewColumn_set_sort_indicator(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_tree_view_column_set_sort_indicator(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeViewColumn_set_sort_order(value instance_, value order) {
  CAMLparam2(instance_, order);
  gtk_tree_view_column_set_sort_order(GObject_val(instance_), Int_val(order));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeViewColumn_set_spacing(value instance_, value spacing) {
  CAMLparam2(instance_, spacing);
  gtk_tree_view_column_set_spacing(GObject_val(instance_), Long_val(spacing));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeViewColumn_set_title(value instance_, value title) {
  CAMLparam2(instance_, title);
  gtk_tree_view_column_set_title(GObject_val(instance_), String_val(title));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeViewColumn_set_visible(value instance_, value visible) {
  CAMLparam2(instance_, visible);
  gtk_tree_view_column_set_visible(GObject_val(instance_), Bool_val(visible));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_TreeViewColumn_set_widget(value instance_, value widget) {
  CAMLparam2(instance_, widget);
  gtk_tree_view_column_set_widget(GObject_val(instance_), GObject_val(widget));
  CAMLreturn(Val_unit);
}

void ml_Gtk_TreeViewColumn_signal_handler_clicked(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_TreeViewColumn_signal_connect_clicked(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "clicked", ml_Gtk_TreeViewColumn_signal_handler_clicked, callback);
}

CAMLprim value ml_Gtk_Video_new() {
  CAMLparam0();
  void * result = gtk_video_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Video_new_for_media_stream(value stream) {
  CAMLparam1(stream);
  void * result = gtk_video_new_for_media_stream(GObject_val(stream));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Video_new_for_resource(value resource_path) {
  CAMLparam1(resource_path);
  void * result = gtk_video_new_for_resource(String_val(resource_path));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Video_get_autoplay(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_video_get_autoplay(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Video_get_loop(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_video_get_loop(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Video_get_media_stream(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_video_get_media_stream(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Video_set_autoplay(value instance_, value autoplay) {
  CAMLparam2(instance_, autoplay);
  gtk_video_set_autoplay(GObject_val(instance_), Bool_val(autoplay));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Video_set_loop(value instance_, value loop) {
  CAMLparam2(instance_, loop);
  gtk_video_set_loop(GObject_val(instance_), Bool_val(loop));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Video_set_media_stream(value instance_, value stream) {
  CAMLparam2(instance_, stream);
  gtk_video_set_media_stream(GObject_val(instance_), GObject_val(stream));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Video_set_resource(value instance_, value resource_path) {
  CAMLparam2(instance_, resource_path);
  gtk_video_set_resource(GObject_val(instance_), String_val(resource_path));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Viewport_new(value hadjustment, value vadjustment) {
  CAMLparam2(hadjustment, vadjustment);
  void * result = gtk_viewport_new(GObject_val(hadjustment), GObject_val(vadjustment));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Viewport_get_child(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_viewport_get_child(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Viewport_get_scroll_to_focus(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_viewport_get_scroll_to_focus(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Viewport_set_child(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_viewport_set_child(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Viewport_set_scroll_to_focus(value instance_, value scroll_to_focus) {
  CAMLparam2(instance_, scroll_to_focus);
  gtk_viewport_set_scroll_to_focus(GObject_val(instance_), Bool_val(scroll_to_focus));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_VolumeButton_new() {
  CAMLparam0();
  void * result = gtk_volume_button_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Widget_action_set_enabled(value instance_, value action_name, value enabled) {
  CAMLparam3(instance_, action_name, enabled);
  gtk_widget_action_set_enabled(GObject_val(instance_), String_val(action_name), Bool_val(enabled));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_activate(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_widget_activate(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_activate_default(value instance_) {
  CAMLparam1(instance_);
  gtk_widget_activate_default(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_add_css_class(value instance_, value css_class) {
  CAMLparam2(instance_, css_class);
  gtk_widget_add_css_class(GObject_val(instance_), String_val(css_class));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_add_mnemonic_label(value instance_, value label) {
  CAMLparam2(instance_, label);
  gtk_widget_add_mnemonic_label(GObject_val(instance_), GObject_val(label));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_child_focus(value instance_, value direction) {
  CAMLparam2(instance_, direction);
  gboolean result = gtk_widget_child_focus(GObject_val(instance_), Int_val(direction));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_compute_expand(value instance_, value orientation) {
  CAMLparam2(instance_, orientation);
  gboolean result = gtk_widget_compute_expand(GObject_val(instance_), Int_val(orientation));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_drag_check_threshold(value instance_, value start_x, value start_y, value current_x, value current_y) {
  CAMLparam5(instance_, start_x, start_y, current_x, current_y);
  gboolean result = gtk_drag_check_threshold(GObject_val(instance_), Long_val(start_x), Long_val(start_y), Long_val(current_x), Long_val(current_y));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_error_bell(value instance_) {
  CAMLparam1(instance_);
  gtk_widget_error_bell(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_get_allocated_baseline(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_widget_get_allocated_baseline(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Widget_get_allocated_height(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_widget_get_allocated_height(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Widget_get_allocated_width(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_widget_get_allocated_width(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Widget_get_can_focus(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_widget_get_can_focus(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_get_can_target(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_widget_get_can_target(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_get_child_visible(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_widget_get_child_visible(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_get_clipboard(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_widget_get_clipboard(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Widget_get_cursor(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_widget_get_cursor(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Widget_get_direction(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_widget_get_direction(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_Widget_get_display(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_widget_get_display(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Widget_get_first_child(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_widget_get_first_child(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Widget_get_focus_child(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_widget_get_focus_child(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Widget_get_focus_on_click(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_widget_get_focus_on_click(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_get_focusable(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_widget_get_focusable(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_get_frame_clock(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_widget_get_frame_clock(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Widget_get_halign(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_widget_get_halign(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_Widget_get_has_tooltip(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_widget_get_has_tooltip(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_get_height(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_widget_get_height(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Widget_get_hexpand(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_widget_get_hexpand(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_get_hexpand_set(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_widget_get_hexpand_set(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_get_last_child(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_widget_get_last_child(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Widget_get_layout_manager(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_widget_get_layout_manager(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Widget_get_mapped(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_widget_get_mapped(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_get_margin_bottom(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_widget_get_margin_bottom(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Widget_get_margin_end(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_widget_get_margin_end(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Widget_get_margin_start(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_widget_get_margin_start(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Widget_get_margin_top(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_widget_get_margin_top(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Widget_get_next_sibling(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_widget_get_next_sibling(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Widget_get_overflow(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_widget_get_overflow(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_Widget_get_parent(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_widget_get_parent(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Widget_get_prev_sibling(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_widget_get_prev_sibling(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Widget_get_primary_clipboard(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_widget_get_primary_clipboard(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Widget_get_realized(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_widget_get_realized(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_get_receives_default(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_widget_get_receives_default(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_get_request_mode(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_widget_get_request_mode(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_Widget_get_scale_factor(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_widget_get_scale_factor(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Widget_get_sensitive(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_widget_get_sensitive(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_get_settings(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_widget_get_settings(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Widget_get_size(value instance_, value orientation) {
  CAMLparam2(instance_, orientation);
  gint32 result = gtk_widget_get_size(GObject_val(instance_), Int_val(orientation));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Widget_get_style_context(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_widget_get_style_context(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Widget_get_valign(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_widget_get_valign(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_Widget_get_vexpand(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_widget_get_vexpand(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_get_vexpand_set(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_widget_get_vexpand_set(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_get_visible(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_widget_get_visible(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_get_width(value instance_) {
  CAMLparam1(instance_);
  gint32 result = gtk_widget_get_width(GObject_val(instance_));
  CAMLreturn(Val_long(result));
}

CAMLprim value ml_Gtk_Widget_grab_focus(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_widget_grab_focus(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_has_css_class(value instance_, value css_class) {
  CAMLparam2(instance_, css_class);
  gboolean result = gtk_widget_has_css_class(GObject_val(instance_), String_val(css_class));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_has_default(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_widget_has_default(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_has_focus(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_widget_has_focus(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_has_visible_focus(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_widget_has_visible_focus(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_hide(value instance_) {
  CAMLparam1(instance_);
  gtk_widget_hide(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_in_destruction(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_widget_in_destruction(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_init_template(value instance_) {
  CAMLparam1(instance_);
  gtk_widget_init_template(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_insert_after(value instance_, value parent, value previous_sibling) {
  CAMLparam3(instance_, parent, previous_sibling);
  gtk_widget_insert_after(GObject_val(instance_), GObject_val(parent), GObject_val(previous_sibling));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_insert_before(value instance_, value parent, value next_sibling) {
  CAMLparam3(instance_, parent, next_sibling);
  gtk_widget_insert_before(GObject_val(instance_), GObject_val(parent), GObject_val(next_sibling));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_is_ancestor(value instance_, value ancestor) {
  CAMLparam2(instance_, ancestor);
  gboolean result = gtk_widget_is_ancestor(GObject_val(instance_), GObject_val(ancestor));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_is_drawable(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_widget_is_drawable(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_is_focus(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_widget_is_focus(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_is_sensitive(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_widget_is_sensitive(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_is_visible(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_widget_is_visible(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_keynav_failed(value instance_, value direction) {
  CAMLparam2(instance_, direction);
  gboolean result = gtk_widget_keynav_failed(GObject_val(instance_), Int_val(direction));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_map(value instance_) {
  CAMLparam1(instance_);
  gtk_widget_map(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_mnemonic_activate(value instance_, value group_cycling) {
  CAMLparam2(instance_, group_cycling);
  gboolean result = gtk_widget_mnemonic_activate(GObject_val(instance_), Bool_val(group_cycling));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_queue_allocate(value instance_) {
  CAMLparam1(instance_);
  gtk_widget_queue_allocate(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_queue_draw(value instance_) {
  CAMLparam1(instance_);
  gtk_widget_queue_draw(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_queue_resize(value instance_) {
  CAMLparam1(instance_);
  gtk_widget_queue_resize(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_realize(value instance_) {
  CAMLparam1(instance_);
  gtk_widget_realize(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_remove_controller(value instance_, value controller) {
  CAMLparam2(instance_, controller);
  gtk_widget_remove_controller(GObject_val(instance_), GObject_val(controller));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_remove_css_class(value instance_, value css_class) {
  CAMLparam2(instance_, css_class);
  gtk_widget_remove_css_class(GObject_val(instance_), String_val(css_class));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_remove_mnemonic_label(value instance_, value label) {
  CAMLparam2(instance_, label);
  gtk_widget_remove_mnemonic_label(GObject_val(instance_), GObject_val(label));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_remove_tick_callback(value instance_, value id) {
  CAMLparam2(instance_, id);
  gtk_widget_remove_tick_callback(GObject_val(instance_), Long_val(id));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_set_can_focus(value instance_, value can_focus) {
  CAMLparam2(instance_, can_focus);
  gtk_widget_set_can_focus(GObject_val(instance_), Bool_val(can_focus));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_set_can_target(value instance_, value can_target) {
  CAMLparam2(instance_, can_target);
  gtk_widget_set_can_target(GObject_val(instance_), Bool_val(can_target));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_set_child_visible(value instance_, value child_visible) {
  CAMLparam2(instance_, child_visible);
  gtk_widget_set_child_visible(GObject_val(instance_), Bool_val(child_visible));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_set_cursor(value instance_, value cursor) {
  CAMLparam2(instance_, cursor);
  gtk_widget_set_cursor(GObject_val(instance_), GObject_val(cursor));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_set_cursor_from_name(value instance_, value name) {
  CAMLparam2(instance_, name);
  gtk_widget_set_cursor_from_name(GObject_val(instance_), String_val(name));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_set_direction(value instance_, value dir) {
  CAMLparam2(instance_, dir);
  gtk_widget_set_direction(GObject_val(instance_), Int_val(dir));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_set_focus_child(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_widget_set_focus_child(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_set_focus_on_click(value instance_, value focus_on_click) {
  CAMLparam2(instance_, focus_on_click);
  gtk_widget_set_focus_on_click(GObject_val(instance_), Bool_val(focus_on_click));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_set_focusable(value instance_, value focusable) {
  CAMLparam2(instance_, focusable);
  gtk_widget_set_focusable(GObject_val(instance_), Bool_val(focusable));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_set_halign(value instance_, value align) {
  CAMLparam2(instance_, align);
  gtk_widget_set_halign(GObject_val(instance_), Int_val(align));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_set_has_tooltip(value instance_, value has_tooltip) {
  CAMLparam2(instance_, has_tooltip);
  gtk_widget_set_has_tooltip(GObject_val(instance_), Bool_val(has_tooltip));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_set_hexpand(value instance_, value expand) {
  CAMLparam2(instance_, expand);
  gtk_widget_set_hexpand(GObject_val(instance_), Bool_val(expand));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_set_hexpand_set(value instance_, value set) {
  CAMLparam2(instance_, set);
  gtk_widget_set_hexpand_set(GObject_val(instance_), Bool_val(set));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_set_margin_bottom(value instance_, value margin) {
  CAMLparam2(instance_, margin);
  gtk_widget_set_margin_bottom(GObject_val(instance_), Long_val(margin));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_set_margin_end(value instance_, value margin) {
  CAMLparam2(instance_, margin);
  gtk_widget_set_margin_end(GObject_val(instance_), Long_val(margin));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_set_margin_start(value instance_, value margin) {
  CAMLparam2(instance_, margin);
  gtk_widget_set_margin_start(GObject_val(instance_), Long_val(margin));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_set_margin_top(value instance_, value margin) {
  CAMLparam2(instance_, margin);
  gtk_widget_set_margin_top(GObject_val(instance_), Long_val(margin));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_set_name(value instance_, value name) {
  CAMLparam2(instance_, name);
  gtk_widget_set_name(GObject_val(instance_), String_val(name));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_set_overflow(value instance_, value overflow) {
  CAMLparam2(instance_, overflow);
  gtk_widget_set_overflow(GObject_val(instance_), Int_val(overflow));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_set_parent(value instance_, value parent) {
  CAMLparam2(instance_, parent);
  gtk_widget_set_parent(GObject_val(instance_), GObject_val(parent));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_set_receives_default(value instance_, value receives_default) {
  CAMLparam2(instance_, receives_default);
  gtk_widget_set_receives_default(GObject_val(instance_), Bool_val(receives_default));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_set_sensitive(value instance_, value sensitive) {
  CAMLparam2(instance_, sensitive);
  gtk_widget_set_sensitive(GObject_val(instance_), Bool_val(sensitive));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_set_size_request(value instance_, value width, value height) {
  CAMLparam3(instance_, width, height);
  gtk_widget_set_size_request(GObject_val(instance_), Long_val(width), Long_val(height));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_set_state_flags(value instance_, value flags, value clear) {
  CAMLparam3(instance_, flags, clear);
  gtk_widget_set_state_flags(GObject_val(instance_), Int_val(flags), Bool_val(clear));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_set_tooltip_markup(value instance_, value markup) {
  CAMLparam2(instance_, markup);
  gtk_widget_set_tooltip_markup(GObject_val(instance_), String_val(markup));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_set_tooltip_text(value instance_, value text) {
  CAMLparam2(instance_, text);
  gtk_widget_set_tooltip_text(GObject_val(instance_), String_val(text));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_set_valign(value instance_, value align) {
  CAMLparam2(instance_, align);
  gtk_widget_set_valign(GObject_val(instance_), Int_val(align));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_set_vexpand(value instance_, value expand) {
  CAMLparam2(instance_, expand);
  gtk_widget_set_vexpand(GObject_val(instance_), Bool_val(expand));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_set_vexpand_set(value instance_, value set) {
  CAMLparam2(instance_, set);
  gtk_widget_set_vexpand_set(GObject_val(instance_), Bool_val(set));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_set_visible(value instance_, value visible) {
  CAMLparam2(instance_, visible);
  gtk_widget_set_visible(GObject_val(instance_), Bool_val(visible));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_should_layout(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_widget_should_layout(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Widget_show(value instance_) {
  CAMLparam1(instance_);
  gtk_widget_show(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_snapshot_child(value instance_, value child, value snapshot) {
  CAMLparam3(instance_, child, snapshot);
  gtk_widget_snapshot_child(GObject_val(instance_), GObject_val(child), GObject_val(snapshot));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_trigger_tooltip_query(value instance_) {
  CAMLparam1(instance_);
  gtk_widget_trigger_tooltip_query(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_unmap(value instance_) {
  CAMLparam1(instance_);
  gtk_widget_unmap(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_unparent(value instance_) {
  CAMLparam1(instance_);
  gtk_widget_unparent(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_unrealize(value instance_) {
  CAMLparam1(instance_);
  gtk_widget_unrealize(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Widget_unset_state_flags(value instance_, value flags) {
  CAMLparam2(instance_, flags);
  gtk_widget_unset_state_flags(GObject_val(instance_), Int_val(flags));
  CAMLreturn(Val_unit);
}

void ml_Gtk_Widget_signal_handler_destroy(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Widget_signal_connect_destroy(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "destroy", ml_Gtk_Widget_signal_handler_destroy, callback);
}

void ml_Gtk_Widget_signal_handler_direction_changed(GObject *instance_, int previous_direction, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_int(previous_direction);
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Widget_signal_connect_direction_changed(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "direction-changed", ml_Gtk_Widget_signal_handler_direction_changed, callback);
}

void ml_Gtk_Widget_signal_handler_hide(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Widget_signal_connect_hide(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "hide", ml_Gtk_Widget_signal_handler_hide, callback);
}

gboolean ml_Gtk_Widget_signal_handler_keynav_failed(GObject *instance_, int direction, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_int(direction);
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_Widget_signal_connect_keynav_failed(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "keynav-failed", ml_Gtk_Widget_signal_handler_keynav_failed, callback);
}

void ml_Gtk_Widget_signal_handler_map(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Widget_signal_connect_map(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "map", ml_Gtk_Widget_signal_handler_map, callback);
}

gboolean ml_Gtk_Widget_signal_handler_mnemonic_activate(GObject *instance_, gboolean group_cycling, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = (group_cycling ? Val_true : Val_false);
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_Widget_signal_connect_mnemonic_activate(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "mnemonic-activate", ml_Gtk_Widget_signal_handler_mnemonic_activate, callback);
}

void ml_Gtk_Widget_signal_handler_move_focus(GObject *instance_, int direction, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_int(direction);
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Widget_signal_connect_move_focus(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "move-focus", ml_Gtk_Widget_signal_handler_move_focus, callback);
}

gboolean ml_Gtk_Widget_signal_handler_query_tooltip(GObject *instance_, gint32 x, gint32 y, gboolean keyboard_mode, void * tooltip, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 4);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_long(x);
  args[1] = Val_long(y);
  args[2] = (keyboard_mode ? Val_true : Val_false);
  args[3] = Val_GObject((void *)(tooltip));
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 4, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_Widget_signal_connect_query_tooltip(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "query-tooltip", ml_Gtk_Widget_signal_handler_query_tooltip, callback);
}

void ml_Gtk_Widget_signal_handler_realize(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Widget_signal_connect_realize(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "realize", ml_Gtk_Widget_signal_handler_realize, callback);
}

void ml_Gtk_Widget_signal_handler_show(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Widget_signal_connect_show(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "show", ml_Gtk_Widget_signal_handler_show, callback);
}

void ml_Gtk_Widget_signal_handler_unmap(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Widget_signal_connect_unmap(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "unmap", ml_Gtk_Widget_signal_handler_unmap, callback);
}

void ml_Gtk_Widget_signal_handler_unrealize(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Widget_signal_connect_unrealize(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "unrealize", ml_Gtk_Widget_signal_handler_unrealize, callback);
}

CAMLprim value ml_Gtk_WidgetPaintable_new(value widget) {
  CAMLparam1(widget);
  void * result = gtk_widget_paintable_new(GObject_val(widget));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_WidgetPaintable_get_widget(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_widget_paintable_get_widget(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_WidgetPaintable_set_widget(value instance_, value widget) {
  CAMLparam2(instance_, widget);
  gtk_widget_paintable_set_widget(GObject_val(instance_), GObject_val(widget));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Window_new() {
  CAMLparam0();
  void * result = gtk_window_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Window_close(value instance_) {
  CAMLparam1(instance_);
  gtk_window_close(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Window_destroy(value instance_) {
  CAMLparam1(instance_);
  gtk_window_destroy(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Window_fullscreen(value instance_) {
  CAMLparam1(instance_);
  gtk_window_fullscreen(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Window_fullscreen_on_monitor(value instance_, value monitor) {
  CAMLparam2(instance_, monitor);
  gtk_window_fullscreen_on_monitor(GObject_val(instance_), GObject_val(monitor));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Window_get_application(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_window_get_application(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Window_get_child(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_window_get_child(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Window_get_decorated(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_window_get_decorated(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Window_get_default_widget(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_window_get_default_widget(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Window_get_deletable(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_window_get_deletable(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Window_get_destroy_with_parent(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_window_get_destroy_with_parent(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Window_get_focus(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_window_get_focus(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Window_get_focus_visible(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_window_get_focus_visible(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Window_get_group(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_window_get_group(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Window_get_handle_menubar_accel(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_window_get_handle_menubar_accel(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Window_get_hide_on_close(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_window_get_hide_on_close(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Window_get_mnemonics_visible(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_window_get_mnemonics_visible(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Window_get_modal(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_window_get_modal(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Window_get_resizable(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_window_get_resizable(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Window_get_titlebar(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_window_get_titlebar(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Window_get_transient_for(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_window_get_transient_for(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_Window_has_group(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_window_has_group(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Window_is_active(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_window_is_active(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Window_is_fullscreen(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_window_is_fullscreen(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Window_is_maximized(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_window_is_maximized(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_Window_maximize(value instance_) {
  CAMLparam1(instance_);
  gtk_window_maximize(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Window_minimize(value instance_) {
  CAMLparam1(instance_);
  gtk_window_minimize(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Window_present(value instance_) {
  CAMLparam1(instance_);
  gtk_window_present(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Window_present_with_time(value instance_, value timestamp) {
  CAMLparam2(instance_, timestamp);
  gtk_window_present_with_time(GObject_val(instance_), Long_val(timestamp));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Window_set_application(value instance_, value application) {
  CAMLparam2(instance_, application);
  gtk_window_set_application(GObject_val(instance_), GObject_val(application));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Window_set_child(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_window_set_child(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Window_set_decorated(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_window_set_decorated(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Window_set_default_size(value instance_, value width, value height) {
  CAMLparam3(instance_, width, height);
  gtk_window_set_default_size(GObject_val(instance_), Long_val(width), Long_val(height));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Window_set_default_widget(value instance_, value default_widget) {
  CAMLparam2(instance_, default_widget);
  gtk_window_set_default_widget(GObject_val(instance_), GObject_val(default_widget));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Window_set_deletable(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_window_set_deletable(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Window_set_destroy_with_parent(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_window_set_destroy_with_parent(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Window_set_display(value instance_, value display) {
  CAMLparam2(instance_, display);
  gtk_window_set_display(GObject_val(instance_), GObject_val(display));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Window_set_focus(value instance_, value focus) {
  CAMLparam2(instance_, focus);
  gtk_window_set_focus(GObject_val(instance_), GObject_val(focus));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Window_set_focus_visible(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_window_set_focus_visible(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Window_set_handle_menubar_accel(value instance_, value handle_menubar_accel) {
  CAMLparam2(instance_, handle_menubar_accel);
  gtk_window_set_handle_menubar_accel(GObject_val(instance_), Bool_val(handle_menubar_accel));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Window_set_hide_on_close(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_window_set_hide_on_close(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Window_set_icon_name(value instance_, value name) {
  CAMLparam2(instance_, name);
  gtk_window_set_icon_name(GObject_val(instance_), String_val(name));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Window_set_mnemonics_visible(value instance_, value setting) {
  CAMLparam2(instance_, setting);
  gtk_window_set_mnemonics_visible(GObject_val(instance_), Bool_val(setting));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Window_set_modal(value instance_, value modal) {
  CAMLparam2(instance_, modal);
  gtk_window_set_modal(GObject_val(instance_), Bool_val(modal));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Window_set_resizable(value instance_, value resizable) {
  CAMLparam2(instance_, resizable);
  gtk_window_set_resizable(GObject_val(instance_), Bool_val(resizable));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Window_set_startup_id(value instance_, value startup_id) {
  CAMLparam2(instance_, startup_id);
  gtk_window_set_startup_id(GObject_val(instance_), String_val(startup_id));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Window_set_title(value instance_, value title) {
  CAMLparam2(instance_, title);
  gtk_window_set_title(GObject_val(instance_), String_val(title));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Window_set_titlebar(value instance_, value titlebar) {
  CAMLparam2(instance_, titlebar);
  gtk_window_set_titlebar(GObject_val(instance_), GObject_val(titlebar));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Window_set_transient_for(value instance_, value parent) {
  CAMLparam2(instance_, parent);
  gtk_window_set_transient_for(GObject_val(instance_), GObject_val(parent));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Window_unfullscreen(value instance_) {
  CAMLparam1(instance_);
  gtk_window_unfullscreen(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Window_unmaximize(value instance_) {
  CAMLparam1(instance_);
  gtk_window_unmaximize(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_Window_unminimize(value instance_) {
  CAMLparam1(instance_);
  gtk_window_unminimize(GObject_val(instance_));
  CAMLreturn(Val_unit);
}

void ml_Gtk_Window_signal_handler_activate_default(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Window_signal_connect_activate_default(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "activate-default", ml_Gtk_Window_signal_handler_activate_default, callback);
}

void ml_Gtk_Window_signal_handler_activate_focus(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Window_signal_connect_activate_focus(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "activate-focus", ml_Gtk_Window_signal_handler_activate_focus, callback);
}

gboolean ml_Gtk_Window_signal_handler_close_request(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_Window_signal_connect_close_request(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "close-request", ml_Gtk_Window_signal_handler_close_request, callback);
}

gboolean ml_Gtk_Window_signal_handler_enable_debugging(GObject *instance_, gboolean toggle, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = (toggle ? Val_true : Val_false);
  gboolean result = Bool_val(caml_callbackN(*callbackCell, 1, args));
  callbacks_allowed = true;
  CAMLreturnT(gboolean, result);
}

CAMLprim value ml_Gtk_Window_signal_connect_enable_debugging(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "enable-debugging", ml_Gtk_Window_signal_handler_enable_debugging, callback);
}

void ml_Gtk_Window_signal_handler_keys_changed(GObject *instance_, value *callbackCell) {
  CAMLparam0();
  CAMLlocalN(args, 1);
  if (!callbacks_allowed) abort();
  callbacks_allowed = false;
  args[0] = Val_unit;
  ;caml_callbackN(*callbackCell, 1, args);
  callbacks_allowed = true;
  CAMLreturn0;
}

CAMLprim value ml_Gtk_Window_signal_connect_keys_changed(value instance_, value callback) {
  return ml_GObject_signal_connect(instance_, "keys-changed", ml_Gtk_Window_signal_handler_keys_changed, callback);
}

CAMLprim value ml_Gtk_WindowControls_new(value side) {
  CAMLparam1(side);
  void * result = gtk_window_controls_new(Int_val(side));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_WindowControls_get_empty(value instance_) {
  CAMLparam1(instance_);
  gboolean result = gtk_window_controls_get_empty(GObject_val(instance_));
  CAMLreturn((result ? Val_true : Val_false));
}

CAMLprim value ml_Gtk_WindowControls_get_side(value instance_) {
  CAMLparam1(instance_);
  int result = gtk_window_controls_get_side(GObject_val(instance_));
  CAMLreturn(Val_int(result));
}

CAMLprim value ml_Gtk_WindowControls_set_decoration_layout(value instance_, value layout) {
  CAMLparam2(instance_, layout);
  gtk_window_controls_set_decoration_layout(GObject_val(instance_), String_val(layout));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_WindowControls_set_side(value instance_, value side) {
  CAMLparam2(instance_, side);
  gtk_window_controls_set_side(GObject_val(instance_), Int_val(side));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_WindowGroup_new() {
  CAMLparam0();
  void * result = gtk_window_group_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_WindowGroup_add_window(value instance_, value window) {
  CAMLparam2(instance_, window);
  gtk_window_group_add_window(GObject_val(instance_), GObject_val(window));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_WindowGroup_remove_window(value instance_, value window) {
  CAMLparam2(instance_, window);
  gtk_window_group_remove_window(GObject_val(instance_), GObject_val(window));
  CAMLreturn(Val_unit);
}

CAMLprim value ml_Gtk_WindowHandle_new() {
  CAMLparam0();
  void * result = gtk_window_handle_new();
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_WindowHandle_get_child(value instance_) {
  CAMLparam1(instance_);
  void * result = gtk_window_handle_get_child(GObject_val(instance_));
  CAMLreturn(Val_GObject((void *)(result)));
}

CAMLprim value ml_Gtk_WindowHandle_set_child(value instance_, value child) {
  CAMLparam2(instance_, child);
  gtk_window_handle_set_child(GObject_val(instance_), GObject_val(child));
  CAMLreturn(Val_unit);
}
