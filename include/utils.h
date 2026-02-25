#ifndef UTILS_H
#define UTILS_H

/*
 * get_mime_type - Return MIME type string for a given file extension
 * e.g. ".html" -> "text/html", ".jpg" -> "image/jpeg"
 */
const char *get_mime_type(const char *path);

/*
 * log_message - Write a timestamped message to stdout/log file
 */
void log_message(const char *level, const char *fmt, ...);

#endif /* UTILS_H */
