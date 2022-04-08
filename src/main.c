#include <window/window.h>

int main() {
    int event;
    create_window();
    while (1) {
        window_draw_rectangle();
        event = window_get_event();
        if (event == -1) {
            break;
        }
    }
    destroy_window();
    return 0;
}
