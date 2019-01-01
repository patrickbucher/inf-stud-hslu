/**
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct channel {
    float value;
    uint32_t unit_id;
    char unit_string[64];
    char channel_name[64];
} channel;

typedef struct sensor {
    uint32_t serial_number;
    uint8_t product_id;
    char device_name[64];
    uint8_t n_channels;
    channel **channels;
} sensor;

typedef struct {
    uint8_t n_sensors;
    sensor **sensors;
} oak_sensor;

oak_sensor *scan_sensors();
int read_values(oak_sensor *);
void output(oak_sensor *);
void cleanup(oak_sensor *);

int main()
{
    oak_sensor *oak;

    oak = scan_sensors();
    read_values(oak);
    output(oak);
    cleanup(oak);

    return 0;
}

oak_sensor *scan_sensors()
{
    oak_sensor *oak;
    sensor *atmos, *humid, *accel, *curnt, *lumin;
    channel *c_press, *c_temp, *c_humid, *c_x, *c_y, *c_z, *c_curr, *c_illu;

    c_press = (channel *)malloc(sizeof(channel));
    c_press->unit_id = 23;
    strcpy(c_press->unit_string, "Pa");
    strcpy(c_press->channel_name, "Pressure");

    c_temp  = (channel *)malloc(sizeof(channel));
    c_temp->unit_id = 37;
    strcpy(c_temp->unit_string, "K");
    strcpy(c_temp->channel_name, "Temperature");

    c_humid  = (channel *)malloc(sizeof(channel));
    c_humid->unit_id = 49;
    strcpy(c_humid->unit_string, "% relative");
    strcpy(c_temp->channel_name, "Humidity");

    c_x = (channel *)malloc(sizeof(channel));
    c_x->unit_id = 55;
    strcpy(c_x->unit_string, "m/s^2");
    strcpy(c_x->channel_name, "x");

    c_y = (channel *)malloc(sizeof(channel));
    c_y->unit_id = 55;
    strcpy(c_y->unit_string, "m/s^2");
    strcpy(c_y->channel_name, "y");

    c_z = (channel *)malloc(sizeof(channel));
    c_z->unit_id = 55;
    strcpy(c_z->unit_string, "m/s^2");
    strcpy(c_z->channel_name, "z");

    c_curr = (channel *)malloc(sizeof(channel));
    c_curr->unit_id = 13;
    strcpy(c_curr->unit_string, "A");
    strcpy(c_curr->channel_name, "Current (4..20mA)");
    
    c_illu = (channel *)malloc(sizeof(channel));
    c_illu->unit_id = 87;
    strcpy(c_illu->unit_string, "Lux");
    strcpy(c_illu->channel_name, "Illuminance");

    atmos = (sensor*)malloc(sizeof(sensor));
    atmos->serial_number = 11111;
    atmos->product_id = 1;
    strcpy(atmos->device_name, "Atmospheric pressure");
    atmos->n_channels = 2;
    atmos->channels = (channel **)malloc(sizeof(channel *) * atmos->n_channels);
    atmos->channels[0] = c_press;
    atmos->channels[1] = c_temp;

    humid = (sensor *)malloc(sizeof(sensor));
    humid->serial_number = 22222;
    humid->product_id = 2;
    strcpy(humid->device_name, "Humidity");
    humid->n_channels = 2;
    humid->channels = (channel **)malloc(sizeof(channel *) * humid->n_channels);
    humid->channels[0] = c_temp;
    humid->channels[1] = c_humid;

    accel = (sensor *)malloc(sizeof(sensor));
    accel->serial_number = 33333;
    accel->product_id = 3;
    strcpy(accel->device_name, "Acceleration");
    accel->n_channels = 3;
    accel->channels = (channel **)malloc(sizeof(channel *) * accel->n_channels);
    accel->channels[0] = c_x;
    accel->channels[1] = c_y;
    accel->channels[2] = c_z;

    curnt = (sensor *)malloc(sizeof(sensor));
    curnt->serial_number = 44444;
    curnt->product_id = 4;
    strcpy(curnt->device_name, "Current");
    curnt->n_channels = 1;
    curnt->channels = (channel **)malloc(sizeof(channel *) * curnt->n_channels);
    curnt->channels[0] = c_curr;

    lumin = (sensor *)malloc(sizeof(sensor));
    lumin->serial_number = 55555;
    lumin->product_id = 5;
    strcpy(lumin->device_name, "Luminosity");
    lumin->n_channels = 1;
    lumin->channels = (channel **)malloc(sizeof(channel *) * lumin->n_channels);
    lumin->channels[0] = c_illu;

    oak = (oak_sensor*)malloc(sizeof(oak_sensor));
    oak->n_sensors = 5;
    oak->sensors = (sensor **)malloc(sizeof(sensor *) * oak->n_sensors);
    oak->sensors[0] = atmos;
    oak->sensors[1] = humid;
    oak->sensors[2] = accel;
    oak->sensors[3] = curnt;
    oak->sensors[4] = lumin;

    return oak;
}

int read_values(oak_sensor *oak)
{
    oak->sensors[0]->channels[0]->value = 101539.0f;
    oak->sensors[0]->channels[1]->value = 297.7000012f;
    // same as above:
    // oak->sensors[1]->channels[0] = 297->7000012;
    oak->sensors[1]->channels[1]->value = 58.7000001f;
    oak->sensors[2]->channels[0]->value = 0.01f;
    oak->sensors[2]->channels[1]->value = -0.02f;
    oak->sensors[2]->channels[2]->value = 9.81f;
    oak->sensors[3]->channels[0]->value = 0.0075f;
    oak->sensors[4]->channels[0]->value = 12746.0f;

    return 0; // why a return value (see exercise)?
}


void output(oak_sensor *oak)
{
    int s, c;
    sensor *sens;
    channel *chan;

    printf("%d sensors\n", oak->n_sensors);

    for (s = 0; s < oak->n_sensors; s++) {
        sens = oak->sensors[s];
        printf("- %s (SN %d, PID %d) has %d channels\n", sens->device_name,
                sens->serial_number, sens->product_id, sens->n_channels);
        for (c = 0; c < sens->n_channels; c++) {
            chan = sens->channels[c];
            printf("\t- %s measures %s (%d): %f %s\n", chan->channel_name,
                    chan->unit_string, chan->unit_id, chan->value,
                    chan->unit_string);
        }
    }
}

void cleanup(oak_sensor *oak)
{
    int s, c, i, nchans;
    sensor *sens;
    channel *chan, **chanlist, **tmp;
    bool contained;

    // Channels can be referenced from different sensors. In order to make sure
    // that every channel only gets free'd once, store them uniquely in a list.
    nchans = 0;
    chanlist = (channel **)malloc(sizeof(channel *));
    for (s = 0; s < oak->n_sensors; s++) {
        sens = oak->sensors[s];
        for (c = 0; c < sens->n_channels; c++) {
            contained = false;
            chan = sens->channels[c];
            if (nchans == 0) {
                chanlist[nchans++] = chan;
                contained = true;
            } else {
                for (i = 0; i < nchans; i++) {
                    if (chanlist[i] == chan) {
                        contained = true;
                    }
                }
            }
            if (!contained) {
                tmp = (channel **)realloc(chanlist, sizeof(channel *) * (nchans+1));
                if (tmp) {
                    chanlist = tmp;
                    chanlist[nchans++] = chan;
                }
            }
        }
    }

    for (c = 0; c < nchans; c++) {
        free(chanlist[c]);
    }
    free(chanlist);

    for (s = 0; s < oak->n_sensors; s++) {
        free(oak->sensors[s]->channels);
        free(oak->sensors[s]);
    }
    free(oak->sensors);
    free(oak);
}
