#include <stdio.h>
#include "sensor_utils.h"

int read_data(const char *path, float *value) {
    FILE *fp = fopen(path, "r");
    if (!fp) {
        perror("fopen");
        return -1;
    }
    if (fscanf(fp, "%f", value) != 1) {
        fclose(fp);
        return -1;
    }
    fclose(fp);
    return 0;
}

int write_data(const char *path, const char *value) {
    FILE *fp = fopen(path, "w");
    if (!fp) {
        perror("fopen");
        return -1;
    }
    if (fprintf(fp, "%s", value) < 0) {
        fclose(fp);
        return -1;
    }
    fclose(fp);
    return 0;
}
