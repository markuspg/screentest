/* $Id: interface.c,v 1.1.1.1 2001/08/20 18:10:54 kas Exp $ */

/*
 *  Screentest - CRT monitor testing utility.
 *  http://www.fi.muni.cz/~kas/screentest/
 *  Copyright (C) 2001 Jan "Yenya" Kasprzak <kas@fi.muni.cz>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */
/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

GtkWidget *create_mainwin(void)
{
	GtkWidget *mainwin;
	GtkWidget *area;

	mainwin = gtk_window_new(GTK_WINDOW_POPUP);
	gtk_object_set_data(GTK_OBJECT(mainwin), "mainwin", mainwin);
	gtk_widget_set_uposition(mainwin, 0, 0);
	gtk_widget_set_usize(mainwin, 640, 480);
	gtk_window_set_title(GTK_WINDOW(mainwin), "Screen test");
	gtk_window_set_modal(GTK_WINDOW(mainwin), TRUE);
	gtk_window_set_default_size(GTK_WINDOW(mainwin), 640, 480);
	gtk_window_set_policy(GTK_WINDOW(mainwin), FALSE, FALSE, FALSE);

	area = gtk_drawing_area_new();
	gtk_widget_ref(area);
	gtk_object_set_data_full(GTK_OBJECT(mainwin), "area", area,
				 (GtkDestroyNotify) gtk_widget_unref);
	gtk_widget_show(area);
	gtk_container_add(GTK_CONTAINER(mainwin), area);
	GTK_WIDGET_SET_FLAGS(area, GTK_CAN_FOCUS);
	GTK_WIDGET_SET_FLAGS(area, GTK_CAN_DEFAULT);
	gtk_widget_set_events(area,
			      GDK_EXPOSURE_MASK | GDK_BUTTON_PRESS_MASK |
			      GDK_BUTTON_RELEASE_MASK | GDK_KEY_PRESS_MASK
			      | GDK_KEY_RELEASE_MASK);

	gtk_signal_connect(GTK_OBJECT(mainwin), "realize",
			   GTK_SIGNAL_FUNC(on_mainwin_realize), NULL);
	gtk_signal_connect(GTK_OBJECT(area), "button_press_event",
			   GTK_SIGNAL_FUNC(on_area_button_press_event),
			   NULL);
	gtk_signal_connect(GTK_OBJECT(area), "key_press_event",
			   GTK_SIGNAL_FUNC(on_area_key_press_event), NULL);
	gtk_signal_connect(GTK_OBJECT(area), "expose_event",
			   GTK_SIGNAL_FUNC(on_area_expose_event), NULL);
	gtk_signal_connect(GTK_OBJECT(area), "realize",
			   GTK_SIGNAL_FUNC(on_area_realize), NULL);

	gtk_widget_grab_default(area);
	return mainwin;
}

GtkWidget *create_popup(void)
{
	GtkWidget *popup;
	GtkAccelGroup *popup_accels;
	GtkWidget *mode;
	GtkWidget *mode_menu;
	GtkAccelGroup *mode_menu_accels;
	GSList *mode_group = NULL;
	GtkWidget *basic;
	GtkWidget *grid;
	GtkWidget *horizontal;
	GtkWidget *vertical;
	GtkWidget *blink;
	GtkWidget *text;
	GtkWidget *color;
	GtkWidget *color_menu;
	GtkAccelGroup *color_menu_accels;
	GSList *color_group = NULL;
	GtkWidget *white1;
	GtkWidget *red;
	GtkWidget *green;
	GtkWidget *blue;
	GtkWidget *cyan;
	GtkWidget *magenta;
	GtkWidget *yellow;
	GtkWidget *black2;
	GtkWidget *background_color1;
	GtkWidget *background_color1_menu;
	GtkAccelGroup *background_color1_menu_accels;
	GSList *bgcolor_group = NULL;
	GtkWidget *white2;
	GtkWidget *red1;
	GtkWidget *green1;
	GtkWidget *blue1;
	GtkWidget *cyan1;
	GtkWidget *magenta1;
	GtkWidget *yellow1;
	GtkWidget *black1;
	GtkWidget *separator1;
	GtkWidget *exit1;

	popup = gtk_menu_new();
	gtk_object_set_data(GTK_OBJECT(popup), "popup", popup);
	popup_accels = gtk_menu_ensure_uline_accel_group(GTK_MENU(popup));

	mode = gtk_menu_item_new_with_label("Mode");
	gtk_widget_ref(mode);
	gtk_object_set_data_full(GTK_OBJECT(popup), "mode", mode,
				 (GtkDestroyNotify) gtk_widget_unref);
	gtk_widget_show(mode);
	gtk_container_add(GTK_CONTAINER(popup), mode);

	mode_menu = gtk_menu_new();
	gtk_widget_ref(mode_menu);
	gtk_object_set_data_full(GTK_OBJECT(popup), "mode_menu", mode_menu,
				 (GtkDestroyNotify) gtk_widget_unref);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(mode), mode_menu);
	mode_menu_accels =
	    gtk_menu_ensure_uline_accel_group(GTK_MENU(mode_menu));

	basic = gtk_radio_menu_item_new_with_label(mode_group, "Basic");
	mode_group = gtk_radio_menu_item_group(GTK_RADIO_MENU_ITEM(basic));
	gtk_widget_ref(basic);
	gtk_object_set_data_full(GTK_OBJECT(popup), "basic", basic,
				 (GtkDestroyNotify) gtk_widget_unref);
	gtk_widget_show(basic);
	gtk_container_add(GTK_CONTAINER(mode_menu), basic);
	gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(basic), TRUE);
	gtk_check_menu_item_set_show_toggle(GTK_CHECK_MENU_ITEM(basic),
					    TRUE);

	grid = gtk_radio_menu_item_new_with_label(mode_group, "Grid");
	mode_group = gtk_radio_menu_item_group(GTK_RADIO_MENU_ITEM(grid));
	gtk_widget_ref(grid);
	gtk_object_set_data_full(GTK_OBJECT(popup), "grid", grid,
				 (GtkDestroyNotify) gtk_widget_unref);
	gtk_widget_show(grid);
	gtk_container_add(GTK_CONTAINER(mode_menu), grid);
	gtk_check_menu_item_set_show_toggle(GTK_CHECK_MENU_ITEM(grid),
					    TRUE);

	horizontal =
	    gtk_radio_menu_item_new_with_label(mode_group, "Horizontal");
	mode_group =
	    gtk_radio_menu_item_group(GTK_RADIO_MENU_ITEM(horizontal));
	gtk_widget_ref(horizontal);
	gtk_object_set_data_full(GTK_OBJECT(popup), "horizontal",
				 horizontal,
				 (GtkDestroyNotify) gtk_widget_unref);
	gtk_widget_show(horizontal);
	gtk_container_add(GTK_CONTAINER(mode_menu), horizontal);
	gtk_check_menu_item_set_show_toggle(GTK_CHECK_MENU_ITEM
					    (horizontal), TRUE);

	vertical =
	    gtk_radio_menu_item_new_with_label(mode_group, "Vertical");
	mode_group =
	    gtk_radio_menu_item_group(GTK_RADIO_MENU_ITEM(vertical));
	gtk_widget_ref(vertical);
	gtk_object_set_data_full(GTK_OBJECT(popup), "vertical", vertical,
				 (GtkDestroyNotify) gtk_widget_unref);
	gtk_widget_show(vertical);
	gtk_container_add(GTK_CONTAINER(mode_menu), vertical);
	gtk_check_menu_item_set_show_toggle(GTK_CHECK_MENU_ITEM(vertical),
					    TRUE);

	blink = gtk_radio_menu_item_new_with_label(mode_group, "Blink");
	mode_group = gtk_radio_menu_item_group(GTK_RADIO_MENU_ITEM(blink));
	gtk_widget_ref(blink);
	gtk_object_set_data_full(GTK_OBJECT(popup), "blink", blink,
				 (GtkDestroyNotify) gtk_widget_unref);
	gtk_widget_show(blink);
	gtk_container_add(GTK_CONTAINER(mode_menu), blink);
	gtk_check_menu_item_set_show_toggle(GTK_CHECK_MENU_ITEM(blink),
					    TRUE);

	text = gtk_radio_menu_item_new_with_label(mode_group, "Text");
	mode_group = gtk_radio_menu_item_group(GTK_RADIO_MENU_ITEM(text));
	gtk_widget_ref(text);
	gtk_object_set_data_full(GTK_OBJECT(popup), "text", text,
				 (GtkDestroyNotify) gtk_widget_unref);
	gtk_widget_show(text);
	gtk_container_add(GTK_CONTAINER(mode_menu), text);
	gtk_check_menu_item_set_show_toggle(GTK_CHECK_MENU_ITEM(text),
					    TRUE);

	color = gtk_menu_item_new_with_label("Foreground Color");
	gtk_widget_ref(color);
	gtk_object_set_data_full(GTK_OBJECT(popup), "color", color,
				 (GtkDestroyNotify) gtk_widget_unref);
	gtk_widget_show(color);
	gtk_container_add(GTK_CONTAINER(popup), color);

	color_menu = gtk_menu_new();
	gtk_widget_ref(color_menu);
	gtk_object_set_data_full(GTK_OBJECT(popup), "color_menu",
				 color_menu,
				 (GtkDestroyNotify) gtk_widget_unref);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(color), color_menu);
	color_menu_accels =
	    gtk_menu_ensure_uline_accel_group(GTK_MENU(color_menu));

	white1 = gtk_radio_menu_item_new_with_label(color_group, "White");
	color_group =
	    gtk_radio_menu_item_group(GTK_RADIO_MENU_ITEM(white1));
	gtk_widget_ref(white1);
	gtk_object_set_data_full(GTK_OBJECT(popup), "white1", white1,
				 (GtkDestroyNotify) gtk_widget_unref);
	gtk_widget_show(white1);
	gtk_container_add(GTK_CONTAINER(color_menu), white1);
	gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(white1), TRUE);
	gtk_check_menu_item_set_show_toggle(GTK_CHECK_MENU_ITEM(white1),
					    TRUE);

	red = gtk_radio_menu_item_new_with_label(color_group, "Red");
	color_group = gtk_radio_menu_item_group(GTK_RADIO_MENU_ITEM(red));
	gtk_widget_ref(red);
	gtk_object_set_data_full(GTK_OBJECT(popup), "red", red,
				 (GtkDestroyNotify) gtk_widget_unref);
	gtk_widget_show(red);
	gtk_container_add(GTK_CONTAINER(color_menu), red);
	gtk_check_menu_item_set_show_toggle(GTK_CHECK_MENU_ITEM(red),
					    TRUE);

	green = gtk_radio_menu_item_new_with_label(color_group, "Green");
	color_group =
	    gtk_radio_menu_item_group(GTK_RADIO_MENU_ITEM(green));
	gtk_widget_ref(green);
	gtk_object_set_data_full(GTK_OBJECT(popup), "green", green,
				 (GtkDestroyNotify) gtk_widget_unref);
	gtk_widget_show(green);
	gtk_container_add(GTK_CONTAINER(color_menu), green);
	gtk_check_menu_item_set_show_toggle(GTK_CHECK_MENU_ITEM(green),
					    TRUE);

	blue = gtk_radio_menu_item_new_with_label(color_group, "Blue");
	color_group = gtk_radio_menu_item_group(GTK_RADIO_MENU_ITEM(blue));
	gtk_widget_ref(blue);
	gtk_object_set_data_full(GTK_OBJECT(popup), "blue", blue,
				 (GtkDestroyNotify) gtk_widget_unref);
	gtk_widget_show(blue);
	gtk_container_add(GTK_CONTAINER(color_menu), blue);
	gtk_check_menu_item_set_show_toggle(GTK_CHECK_MENU_ITEM(blue),
					    TRUE);

	cyan = gtk_radio_menu_item_new_with_label(color_group, "Cyan");
	color_group = gtk_radio_menu_item_group(GTK_RADIO_MENU_ITEM(cyan));
	gtk_widget_ref(cyan);
	gtk_object_set_data_full(GTK_OBJECT(popup), "cyan", cyan,
				 (GtkDestroyNotify) gtk_widget_unref);
	gtk_widget_show(cyan);
	gtk_container_add(GTK_CONTAINER(color_menu), cyan);
	gtk_check_menu_item_set_show_toggle(GTK_CHECK_MENU_ITEM(cyan),
					    TRUE);

	magenta =
	    gtk_radio_menu_item_new_with_label(color_group, "Magenta");
	color_group =
	    gtk_radio_menu_item_group(GTK_RADIO_MENU_ITEM(magenta));
	gtk_widget_ref(magenta);
	gtk_object_set_data_full(GTK_OBJECT(popup), "magenta", magenta,
				 (GtkDestroyNotify) gtk_widget_unref);
	gtk_widget_show(magenta);
	gtk_container_add(GTK_CONTAINER(color_menu), magenta);
	gtk_check_menu_item_set_show_toggle(GTK_CHECK_MENU_ITEM(magenta),
					    TRUE);

	yellow = gtk_radio_menu_item_new_with_label(color_group, "Yellow");
	color_group =
	    gtk_radio_menu_item_group(GTK_RADIO_MENU_ITEM(yellow));
	gtk_widget_ref(yellow);
	gtk_object_set_data_full(GTK_OBJECT(popup), "yellow", yellow,
				 (GtkDestroyNotify) gtk_widget_unref);
	gtk_widget_show(yellow);
	gtk_container_add(GTK_CONTAINER(color_menu), yellow);
	gtk_check_menu_item_set_show_toggle(GTK_CHECK_MENU_ITEM(yellow),
					    TRUE);

	black2 = gtk_radio_menu_item_new_with_label(color_group, "Black");
	color_group =
	    gtk_radio_menu_item_group(GTK_RADIO_MENU_ITEM(black2));
	gtk_widget_ref(black2);
	gtk_object_set_data_full(GTK_OBJECT(popup), "black2", black2,
				 (GtkDestroyNotify) gtk_widget_unref);
	gtk_widget_show(black2);
	gtk_container_add(GTK_CONTAINER(color_menu), black2);
	gtk_check_menu_item_set_show_toggle(GTK_CHECK_MENU_ITEM(black2),
					    TRUE);

	background_color1 =
	    gtk_menu_item_new_with_label("Background Color");
	gtk_widget_ref(background_color1);
	gtk_object_set_data_full(GTK_OBJECT(popup), "background_color1",
				 background_color1,
				 (GtkDestroyNotify) gtk_widget_unref);
	gtk_widget_show(background_color1);
	gtk_container_add(GTK_CONTAINER(popup), background_color1);

	background_color1_menu = gtk_menu_new();
	gtk_widget_ref(background_color1_menu);
	gtk_object_set_data_full(GTK_OBJECT(popup),
				 "background_color1_menu",
				 background_color1_menu,
				 (GtkDestroyNotify) gtk_widget_unref);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(background_color1),
				  background_color1_menu);
	background_color1_menu_accels =
	    gtk_menu_ensure_uline_accel_group(GTK_MENU
					      (background_color1_menu));

	white2 =
	    gtk_radio_menu_item_new_with_label(bgcolor_group, "White");
	bgcolor_group =
	    gtk_radio_menu_item_group(GTK_RADIO_MENU_ITEM(white2));
	gtk_widget_ref(white2);
	gtk_object_set_data_full(GTK_OBJECT(popup), "white2", white2,
				 (GtkDestroyNotify) gtk_widget_unref);
	gtk_widget_show(white2);
	gtk_container_add(GTK_CONTAINER(background_color1_menu), white2);
	gtk_check_menu_item_set_show_toggle(GTK_CHECK_MENU_ITEM(white2),
					    TRUE);

	red1 = gtk_radio_menu_item_new_with_label(bgcolor_group, "Red");
	bgcolor_group =
	    gtk_radio_menu_item_group(GTK_RADIO_MENU_ITEM(red1));
	gtk_widget_ref(red1);
	gtk_object_set_data_full(GTK_OBJECT(popup), "red1", red1,
				 (GtkDestroyNotify) gtk_widget_unref);
	gtk_widget_show(red1);
	gtk_container_add(GTK_CONTAINER(background_color1_menu), red1);
	gtk_check_menu_item_set_show_toggle(GTK_CHECK_MENU_ITEM(red1),
					    TRUE);

	green1 =
	    gtk_radio_menu_item_new_with_label(bgcolor_group, "Green");
	bgcolor_group =
	    gtk_radio_menu_item_group(GTK_RADIO_MENU_ITEM(green1));
	gtk_widget_ref(green1);
	gtk_object_set_data_full(GTK_OBJECT(popup), "green1", green1,
				 (GtkDestroyNotify) gtk_widget_unref);
	gtk_widget_show(green1);
	gtk_container_add(GTK_CONTAINER(background_color1_menu), green1);
	gtk_check_menu_item_set_show_toggle(GTK_CHECK_MENU_ITEM(green1),
					    TRUE);

	blue1 = gtk_radio_menu_item_new_with_label(bgcolor_group, "Blue");
	bgcolor_group =
	    gtk_radio_menu_item_group(GTK_RADIO_MENU_ITEM(blue1));
	gtk_widget_ref(blue1);
	gtk_object_set_data_full(GTK_OBJECT(popup), "blue1", blue1,
				 (GtkDestroyNotify) gtk_widget_unref);
	gtk_widget_show(blue1);
	gtk_container_add(GTK_CONTAINER(background_color1_menu), blue1);
	gtk_check_menu_item_set_show_toggle(GTK_CHECK_MENU_ITEM(blue1),
					    TRUE);

	cyan1 = gtk_radio_menu_item_new_with_label(bgcolor_group, "Cyan");
	bgcolor_group =
	    gtk_radio_menu_item_group(GTK_RADIO_MENU_ITEM(cyan1));
	gtk_widget_ref(cyan1);
	gtk_object_set_data_full(GTK_OBJECT(popup), "cyan1", cyan1,
				 (GtkDestroyNotify) gtk_widget_unref);
	gtk_widget_show(cyan1);
	gtk_container_add(GTK_CONTAINER(background_color1_menu), cyan1);
	gtk_check_menu_item_set_show_toggle(GTK_CHECK_MENU_ITEM(cyan1),
					    TRUE);

	magenta1 =
	    gtk_radio_menu_item_new_with_label(bgcolor_group, "Magenta");
	bgcolor_group =
	    gtk_radio_menu_item_group(GTK_RADIO_MENU_ITEM(magenta1));
	gtk_widget_ref(magenta1);
	gtk_object_set_data_full(GTK_OBJECT(popup), "magenta1", magenta1,
				 (GtkDestroyNotify) gtk_widget_unref);
	gtk_widget_show(magenta1);
	gtk_container_add(GTK_CONTAINER(background_color1_menu), magenta1);
	gtk_check_menu_item_set_show_toggle(GTK_CHECK_MENU_ITEM(magenta1),
					    TRUE);

	yellow1 =
	    gtk_radio_menu_item_new_with_label(bgcolor_group, "Yellow");
	bgcolor_group =
	    gtk_radio_menu_item_group(GTK_RADIO_MENU_ITEM(yellow1));
	gtk_widget_ref(yellow1);
	gtk_object_set_data_full(GTK_OBJECT(popup), "yellow1", yellow1,
				 (GtkDestroyNotify) gtk_widget_unref);
	gtk_widget_show(yellow1);
	gtk_container_add(GTK_CONTAINER(background_color1_menu), yellow1);
	gtk_check_menu_item_set_show_toggle(GTK_CHECK_MENU_ITEM(yellow1),
					    TRUE);

	black1 =
	    gtk_radio_menu_item_new_with_label(bgcolor_group, "Black");
	bgcolor_group =
	    gtk_radio_menu_item_group(GTK_RADIO_MENU_ITEM(black1));
	gtk_widget_ref(black1);
	gtk_object_set_data_full(GTK_OBJECT(popup), "black1", black1,
				 (GtkDestroyNotify) gtk_widget_unref);
	gtk_widget_show(black1);
	gtk_container_add(GTK_CONTAINER(background_color1_menu), black1);
	gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(black1), TRUE);
	gtk_check_menu_item_set_show_toggle(GTK_CHECK_MENU_ITEM(black1),
					    TRUE);

	separator1 = gtk_menu_item_new();
	gtk_widget_ref(separator1);
	gtk_object_set_data_full(GTK_OBJECT(popup), "separator1",
				 separator1,
				 (GtkDestroyNotify) gtk_widget_unref);
	gtk_widget_show(separator1);
	gtk_container_add(GTK_CONTAINER(popup), separator1);
	gtk_widget_set_sensitive(separator1, FALSE);

	exit1 = gtk_menu_item_new_with_label("Exit");
	gtk_widget_ref(exit1);
	gtk_object_set_data_full(GTK_OBJECT(popup), "exit1", exit1,
				 (GtkDestroyNotify) gtk_widget_unref);
	gtk_widget_show(exit1);
	gtk_container_add(GTK_CONTAINER(popup), exit1);

	gtk_signal_connect(GTK_OBJECT(basic), "activate",
			   GTK_SIGNAL_FUNC(on_mode_change),
			   (gpointer) MODE_BASIC);
	gtk_signal_connect(GTK_OBJECT(grid), "activate",
			   GTK_SIGNAL_FUNC(on_mode_change),
			   (gpointer) MODE_GRID);
	gtk_signal_connect(GTK_OBJECT(horizontal), "activate",
			   GTK_SIGNAL_FUNC(on_mode_change),
			   (gpointer) MODE_HORIZONTAL);
	gtk_signal_connect(GTK_OBJECT(vertical), "activate",
			   GTK_SIGNAL_FUNC(on_mode_change),
			   (gpointer) MODE_VERTICAL);
	gtk_signal_connect(GTK_OBJECT(blink), "activate",
			   GTK_SIGNAL_FUNC(on_mode_change),
			   (gpointer) MODE_BLINK);
	gtk_signal_connect(GTK_OBJECT(text), "activate",
			   GTK_SIGNAL_FUNC(on_mode_change),
			   (gpointer) MODE_TEXT);
	gtk_signal_connect(GTK_OBJECT(white1), "activate",
			   GTK_SIGNAL_FUNC(on_color_change),
			   (gpointer) COLOR_WHITE);
	gtk_signal_connect(GTK_OBJECT(red), "activate",
			   GTK_SIGNAL_FUNC(on_color_change),
			   (gpointer) COLOR_RED);
	gtk_signal_connect(GTK_OBJECT(green), "activate",
			   GTK_SIGNAL_FUNC(on_color_change),
			   (gpointer) COLOR_GREEN);
	gtk_signal_connect(GTK_OBJECT(blue), "activate",
			   GTK_SIGNAL_FUNC(on_color_change),
			   (gpointer) COLOR_BLUE);
	gtk_signal_connect(GTK_OBJECT(cyan), "activate",
			   GTK_SIGNAL_FUNC(on_color_change),
			   (gpointer) COLOR_CYAN);
	gtk_signal_connect(GTK_OBJECT(magenta), "activate",
			   GTK_SIGNAL_FUNC(on_color_change),
			   (gpointer) COLOR_MAGENTA);
	gtk_signal_connect(GTK_OBJECT(yellow), "activate",
			   GTK_SIGNAL_FUNC(on_color_change),
			   (gpointer) COLOR_YELLOW);
	gtk_signal_connect(GTK_OBJECT(black2), "activate",
			   GTK_SIGNAL_FUNC(on_color_change),
			   (gpointer) COLOR_BLACK);
	gtk_signal_connect(GTK_OBJECT(white2), "activate",
			   GTK_SIGNAL_FUNC(on_bgcolor_change),
			   (gpointer) COLOR_WHITE);
	gtk_signal_connect(GTK_OBJECT(red1), "activate",
			   GTK_SIGNAL_FUNC(on_bgcolor_change), NULL);
	gtk_signal_connect(GTK_OBJECT(green1), "activate",
			   GTK_SIGNAL_FUNC(on_bgcolor_change),
			   (gpointer) COLOR_GREEN);
	gtk_signal_connect(GTK_OBJECT(blue1), "activate",
			   GTK_SIGNAL_FUNC(on_bgcolor_change),
			   (gpointer) COLOR_BLUE);
	gtk_signal_connect(GTK_OBJECT(cyan1), "activate",
			   GTK_SIGNAL_FUNC(on_bgcolor_change),
			   (gpointer) COLOR_CYAN);
	gtk_signal_connect(GTK_OBJECT(magenta1), "activate",
			   GTK_SIGNAL_FUNC(on_bgcolor_change),
			   (gpointer) COLOR_MAGENTA);
	gtk_signal_connect(GTK_OBJECT(yellow1), "activate",
			   GTK_SIGNAL_FUNC(on_bgcolor_change),
			   (gpointer) COLOR_YELLOW);
	gtk_signal_connect(GTK_OBJECT(black1), "activate",
			   GTK_SIGNAL_FUNC(on_bgcolor_change),
			   (gpointer) COLOR_BLACK);
	gtk_signal_connect(GTK_OBJECT(exit1), "activate",
			   GTK_SIGNAL_FUNC(on_exit1_activate), NULL);

	return popup;
}
