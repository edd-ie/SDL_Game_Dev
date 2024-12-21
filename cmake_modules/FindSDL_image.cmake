SET(SDL_IMAGE_SEARCH_PATHS
        ~/Library/Frameworks
        /Library/Frameworks
        /usr/local
        /usr
        /sw # Fink
        /opt/local # DarwinPorts
        /opt/csw # Blastwave
        /opt
        ${SDL_IMAGE_PATH}
)


FIND_PATH(SDL_IMAGE_INCLUDE_DIR
        SDL_image.h
        HINTS
        $ENV{SDL_IMAGEDIR}
        PATH_SUFFIXES include/SDL2 include
        PATHS ${SDL_IMAGE_SEARCH_PATHS}
)



find_library(SDL_IMAGE_LIBRARY
        NAMES SDL_image
        PATHS ${SDL_IMAGE_PATH}/lib
        NO_DEFAULT_PATH
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SDL_image # Keep this consistent with find_package(SDL_IMAGE)
        REQUIRED_VARS SDL_IMAGE_INCLUDE_DIR SDL_IMAGE_LIBRARY
)

mark_as_advanced(SDL_IMAGE_INCLUDE_DIR SDL_IMAGE_LIBRARY)

# Define upper case variable for consistency
set(SDL_IMAGE_INCLUDE_DIRS ${SDL_IMAGE_INCLUDE_DIR})
set(SDL_IMAGE_LIBRARIES ${SDL_IMAGE_LIBRARY})