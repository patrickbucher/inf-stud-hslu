/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#ifdef DEBUG
#define DEBUGPRINT(_FMT, ...) \
    fprintf(stderr, "[file %s, line %d: " \
            _FMT, __FILE__, __LINE__, __VA_ARGS__)
#else
#define DEBUGPRINT(_fmt, ...)
#endif
