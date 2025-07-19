package main

import (
	"sort"
	"strings"
)

func removeSubfolders(folders []string) []string {
    // Sort the folders lexicographically. This is crucial because
    // a parent folder will always appear before its sub-folders after sorting.
    // For example, "/a" comes before "/a/b" and "/a/b/c".
    sort.Strings(folders)

    if len(folders) == 0 {
        return []string{}
    }

    // Initialize the result slice with the first folder.
    // The first folder in a sorted list is always a root folder
    // because there cannot be any folder before it that is its parent.
    result := []string{}
    result = append(result, folders[0])

    // currentRoot stores the last confirmed root folder.
    // We compare subsequent folders against this currentRoot.
    currentRoot := folders[0]

    // Iterate through the sorted folders starting from the second one.
    for i := 1; i < len(folders); i++ {
        folder := folders[i]
        
        // Check if the current 'folder' is a sub-folder of 'currentRoot'.
        // A folder 'F' is a sub-folder of 'R' if 'F' starts with 'R' followed by '/'.
        // For example, if currentRoot is "/a", we check if 'folder' starts with "/a/".
        // This ensures that "/ab" is not considered a sub-folder of "/a".
        if strings.HasPrefix(folder, currentRoot+"/") {
            // If it's a sub-folder, we skip it as it should be removed.
            continue
        } else {
            // If it's not a sub-folder of 'currentRoot', then 'folder' itself
            // must be a new root folder (or a sibling of 'currentRoot').
            // Add it to the result and update 'currentRoot' to this new folder.
            result = append(result, folder)
            currentRoot = folder
        }
    }

    return result
}
