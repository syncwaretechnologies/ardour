/*
    Copyright (C) 2007 Tim Mayberry 

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

*/

#ifndef PBD_FILE_UTILS_INCLUDED
#define PBD_FILE_UTILS_INCLUDED

#include <string>
#include <vector>

#include <glibmm/pattern.h>

#include "pbd/search_path.h"

namespace PBD {

/**
 * Get a list of files in a directory.
 * @note You must join path with result to get the absolute path
 * to the file.
 *
 * @param path An Absolute path to a directory
 * @param result A vector of filenames.
 */
void
get_files_in_directory (const std::string& path,
                        std::vector<std::string>& result);

/**
 * Takes a directory path and returns all the files in the directory
 * matching a particular pattern.
 *
 * @param directory A directory path
 * @param pattern A Glib::PatternSpec used to match the files.
 * @param result A vector in which to place the resulting matches.
 */
void
find_matching_files_in_directory (const std::string& directory,
                                  const Glib::PatternSpec& pattern,
                                  std::vector<std::string>& result);

/**
 * Takes a number of directory paths and returns all the files matching
 * a particular pattern.
 *
 * @param paths A vector containing the Absolute paths
 * @param pattern A Glib::PatternSpec used to match the files
 * @param result A vector in which to place the resulting matches.
 */
void
find_matching_files_in_directories (const std::vector<std::string>& directory_paths,
                                    const Glib::PatternSpec& pattern,
                                    std::vector<std::string>& result);

/**
 * Takes a SearchPath and puts a list of all the files in the search path
 * that match pattern into the result vector.
 *
 * @param search_path A SearchPath
 * @param pattern A Glib::PatternSpec used to match the files
 * @param result A vector in which to place the resulting matches.
 */
void
find_matching_files_in_search_path (const SearchPath& search_path,
                                    const Glib::PatternSpec& pattern,
                                    std::vector<std::string>& result);

/**
 * Takes a search path and a file name and place the full path
 * to that file in result if it is found within the search path.
 *
 * @return true If file is found within the search path.
 */
bool
find_file_in_search_path (const SearchPath& search_path,
                          const std::string& filename,
                          std::string& result);

/**
 * Attempt to copy the contents of the file from_path to a new file
 * at path to_path. If to_path exists it is overwritten.
 *
 * @return true if file was successfully copied
 */
bool copy_file(const std::string & from_path, const std::string & to_path);

/**
 * Attempt to copy all regular files from from_path to a new directory.
 * This method does not recurse.
 */
void copy_files(const std::string & from_path, const std::string & to_dir);

/**
 * Take a (possibly) relative path and make it absolute
 * @return An absolute path
 */
std::string get_absolute_path (const std::string &);

/**
 * Find out if `needle' is a file or directory within the
 * directory `haystack'.
 * @return true if it is.
 */
bool path_is_within (const std::string &, std::string);

/**
 * @return true if p1 and p2 both resolve to the same file
 * @param p1 a file path.
 * @param p2 a file path.
 *
 * Uses g_stat to check for identical st_dev and st_ino values.
 */
bool equivalent_paths (const std::string &p1, const std::string &p2);

/// @return true if path at p exists and is writable, false otherwise
bool exists_and_writable(const std::string & p);

} // namespace PBD

#endif
