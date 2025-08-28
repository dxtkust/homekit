#include <stdio.h>
#include <unistd.h>
#include "sensor_utils.h"

const char *pwm_path = "/sys/class/hwmon/hwmon1/pwm1";

int main(void) {
    while (1) {
        float scale, offset, raw, temp;
        float scale1, offset1, raw1, hum;

        if (read_data("/sys/bus/iio/devices/iio:device0/in_temp_scale", &scale) < 0) {
            continue;
        }
        if (read_data("/sys/bus/iio/devices/iio:device0/in_temp_offset", &offset) < 0) {
            continue;
        }
        if (read_data("/sys/bus/iio/devices/iio:device0/in_temp_raw", &raw) < 0) {
            continue;
        }
        temp = (raw + offset) * scale / 1000;

        if (read_data("/sys/bus/iio/devices/iio:device0/in_humidityrelative_scale", &scale1) < 0) {
            continue;
        }
        if (read_data("/sys/bus/iio/devices/iio:device0/in_humidityrelative_offset", &offset1) < 0) {
            continue;
        }
        if (read_data("/sys/bus/iio/devices/iio:device0/in_humidityrelative_raw", &raw1) < 0) {
            continue;
        }
        hum = (raw1 + offset1) * scale1 / 1000;

        if (temp > 29) {
            write_data(pwm_path, "100");
            printf("temp:%f\n", temp);
        } else {
            write_data(pwm_path, "0");
        }

        if (hum > 60) {
            write_data("/sys/devices/platform/led/leds/led1/brightness", "0");
            write_data("/sys/devices/platform/led/leds/led2/brightness", "0");
            write_data("/sys/devices/platform/led/leds/led3/brightness", "1");
            printf("hum:%f\n", hum);
        } else {
            write_data("/sys/devices/platform/led/leds/led1/brightness", "0");
            write_data("/sys/devices/platform/led/leds/led2/brightness", "1");
            write_data("/sys/devices/platform/led/leds/led3/brightness", "0");
        }

        sleep(1);
    }

    return 0;
}
