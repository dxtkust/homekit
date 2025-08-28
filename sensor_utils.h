#ifndef SENSOR_UTILS_H
#define SENSOR_UTILS_H

int read_data(const char *path, float *value);
int write_data(const char *path, const char *value);

#endif // SENSOR_UTILS_H
