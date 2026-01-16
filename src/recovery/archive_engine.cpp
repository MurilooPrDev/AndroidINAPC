#include <archive.h>
#include <archive_entry.h>
#include <string>
#include "../../include/recovery.h"

int extract_archive(const std::string& filename, const std::string& out_path) {
    struct archive *a; struct archive *ext; struct archive_entry *entry;
    a = archive_read_new(); archive_read_support_format_all(a); archive_read_support_filter_all(a);
    ext = archive_write_disk_new(); archive_write_disk_set_options(ext, ARCHIVE_EXTRACT_TIME);
    if (archive_read_open_filename(a, filename.c_str(), 10240)) return 1;
    while (archive_read_next_header(a, &entry) == ARCHIVE_OK) {
        std::string full_out = out_path + "/" + archive_entry_pathname(entry);
        archive_entry_set_pathname(entry, full_out.c_str());
        archive_write_header(ext, entry);
        const void *buff; size_t size; la_int64_t offset;
        while (archive_read_data_block(a, &buff, &size, &offset) == ARCHIVE_OK) {
            archive_write_data_block(ext, buff, size, offset);
        }
        archive_write_finish_entry(ext);
    }
    archive_read_free(a); archive_write_free(ext);
    return 0;
}
