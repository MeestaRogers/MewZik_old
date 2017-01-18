#ifndef __SEARCH_INTERFACE_CPP__
#define __SEARCH_INTERFACE_CPP__

#include "search_interface.h"

Gtk::Widget       *search_bar;

void search_interface_init_widgets(Glib::RefPtr<Gtk::Builder> builder){
    builder->get_widget("mewzik_search_field", search_bar);
}

/***********************************************************************
 ** @name mewzik_on_search_change
 **
 ** @brief      A g_signal callback to when the search entry
 **             field changes text. This will be used to asynchronously
 **             update our results page in the main view.
 **
 ** @param      entry     The search entry widget
 ** @param[in]  userData  The data inside the search entry
 **********************************************************************/
void mewzik_on_search_change(Gtk::SearchEntry *entry, gpointer userData){
    // const gchar *text = gtk_entry_get_text(&(entry->parent));

    // g_print("\n[MewZik DEBUG]: Search Did Change - \"%s\"", text);
}

#endif // __SEARCH_INTERFACE_CPP__
