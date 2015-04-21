# Waze is a free, community-based traffic & navigation app - This is its unofficial Qt port #

Please support this port by donating:

<a href='https://www.paypal.com/cgi-bin/webscr?cmd=_donations&business=WKDDQGMS599AG&lc=IL&item_name=Waze%20Qt%20Port%20Opensource%20Project&item_number=Waze_qt&currency_code=USD'>
<img src='https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif' />
</a>

# Important Note #
Now that Google bought Waze, unless they hire me (damagedspline) to support this port, it is considered dead.
Too many API changed between v2 & the latest v3 so some features stopped working.


# Notes #
  1. The base Waze code that is used is from the Android branch http://www.waze.com/wiki/index.php/Source_code
  1. The following files were modified from the original waze sources (this list is mostly for me in case of codebase upgrade):
    1. roadmap\_gps.c
    1. roadmap\_dbread.c
    1. roadmap\_zlib.h
    1. roadmap\_general\_settings.c
    1. entry\_ssd.h
    1. entry\_ssd.c
    1. generic\_search\_dlg.c
    1. Realtime.c
    1. RealtimeAlerts.c
    1. RealtimeUsers.c
    1. generic\_search.c
    1. update\_range.c
    1. roadmap\_address\_ssd.c
    1. roadmap\_address\_tc.c
    1. roadmap\_search.h
    1. ssd\_text.h
    1. single\_search\_dlg.c
    1. roadmap\_search.c
    1. roadmap\_start.c
    1. roadmap\_res.c
    1. roadmap\_screen.c
    1. roadmap\_screen.h
    1. roadmap\_browser.c
    1. roadmap\_browser.h
    1. string\_parser.c
    1. single\_search\_dlg.c
    1. roadmap.h
    1. roadmap\_option.c
    1. roadmap\_urlschema.c
    1. roadmap\_nmea.c
    1. roadmap\_gpsd2.c
    1. roadmap\_prompts.c
    1. RealtimeAlertsList.c
    1. roadmap\_skin.c
    1. roadmap\_lang.c
    1. roadmap\_factory.c
    1. roadmap\_splash.c
    1. roadmap\_io.c
    1. editor\_download.c
    1. editor\_sync.c
    1. navigate\_main.c
    1. roadmap\_browser.c
    1. roadmap\_download.c
    1. roadmap\_file.h
    1. roadmap\_login\_ssd.c
    1. roadmap\_plugin.c
    1. roadmap\_sound.h
    1. roadmap\_tile\_manager.c
    1. LMap\_Base.h
    1. RealtimeExternalPoi.c
    1. navigate\_bar.c
    1. roadmap\_httpcopy.c
    1. roadmap\_net\_mon.c
    1. roadmap\_recorder.c
    1. roadmap\_recorder\_dlg.c
    1. roadmap\_screen.c
    1. roadmap\_welcome\_wizard.c
    1. ssd\_button.c
    1. ssd\_container.c
    1. ssd\_keyboard\_dialog.c
    1. roadmap\_file.h
    1. roadmap\_net.h
    1. roadmap\_serial.h
  1. The qt directory was based on the qt support from the roadmap project v1.2.1
    * QtCanvas is used instead of agg/ogl
  1. QtMobility integration was added to allow interaction with the GPS, screensaver, etc..
  1. QtSql+SQLite replaces the previous SQLite tile storage & tts layer
  1. Missing the media files which I am not allowed to redistribute
  1. All of the media files (images & sounds) belong to Waze (c)

# How to build and run #
  1. Open the waze.pro file using the QtCreator
  1. Build to the desired platform
  1. To Make a package and install on your device, do a Deploy after the build
  1. Since I am not allowed to distribute the media files, you will have to preform the following steps:
    1. Get the latest Waze apk file you can find (Preferably later then Aug-11)
    1. Extract it using an unzipper
    1. In the extracted assets, copy Freemap to a new folder
    1. Copy the FreemapHD content into the copied Freemap directory and overwrite all files
    1. Execute the following line in the folder:
```
for i in `find ./skins -name '*.bin'`; do [ -f "`echo $i | sed 's/.bin$/.png/'`" ] || mv $i `echo $i | sed 's/.bin$/.png/'`; done
for i in `find ./sound -name '*.bin'`; do [ -f "`echo $i | sed 's/.bin$/.mp3/'`" ] || mv $i `echo $i | sed 's/.bin$/.mp3/'`; done
```
    1. From this project, copy the files under waze/data to the equivalent under the Freemap directory

# TODO list for the next versions (ordered by priority) #

## v0.0.13 - Codename: Faruk - Next release ##
  1. Network fixes
  1. Main UI usability fixes

## v0.0.14 - Codename: Gdalia ##
  1. Rewrite the menus in QML - rethink main view UI - assisted by the community
  1. Add splash screen
  1. Some texts are cropped or missing
  1. Some images are missing
  1. Some action are hard to be done because of too small interface

## v0.1.0 - Codename: Haya ##
  1. Rewrite the map as a QML Location plugin - major performance improvements

# Previous Releases #
## 31-Mar-13 - v0.0.12 - codename: "Erlich" ##
  1. Don't force ports - this will allow using the Waze site servers
  1. Comment the map editing feature
  1. Don't force full screen when running on desktop
  1. Start using Waze v3 icons
  1. Improve the main menu looks
  1. Add a navigate button to the main menu
  1. Move the exit button from the main view to the main menu
  1. Reorganize the buttons in the main view
  1. Remake the ETA bar to be specific for protrait and landscape
  1. Make the next street name bigger

## 9-Jan-13 - v0.0.11 - codename: "Djako" ##
  1. Main view layout change
  1. Waze sounds no longer interrupts external media players

## 25-Oct-12 - v0.0.10 - codename: "Coco" ##
  1. Main view layout change
  1. When navigating, the "Navigate" button allow navigation control
  1. Minimize button added
  1. Browser control orientation fixed
  1. Multitouch on Harmattan fixed
  1. Portrait mode added
  1. Rotate map buttons were added (for platforms without multitouch)
  1. The number of active connections has been limited to ~16
  1. Fix the road signs text (road shields)
  1. Make the map fonts bolder

## 8-Oct-12 - v0.0.9-45 Beta - codename: "Charlie and a Half" ##
  1. Add AMOLED Optimized theme (contribution by ginggs)
  1. Fix routing navigation which sometimes didn't work
  1. Fix several network issues
  1. Small performance improvements
  1. Added Logging settings to General Settings
  1. Added Qt port release version to the about screen
  1. Remake most of the main view in QML
  1. Added portrait mode

## 17-May-12 - v0.0.9 Alpha - codename: "Chico" ##
  1. Added 'backlight stay lit only when plugged' option
  1. Fixed the freeze that occured when data was transmitted, so no more 'Close application...' dialog.
  1. Fixed network data compression (i consider working 90% of the time better than 0% )
  1. Fixed adding a favorite caused crash
  1. Fixed pinging a wazer caused crash
  1. Fixed some crashes that occured when starting a new search

## 2-May-12 - v0.0.8 Alpha - codename: "Batito" ##
  1. Implement secured connections
  1. Fixed empty mood list
  1. Fixed empty car list

## 19-Apr-12 - v0.0.7 Alpha - codename: "Azriel" => new naming convention based on Burekas movie characters ##
  1. Rewrite the network layer to be based on Qt instead of kernel sockets
  1. Rewrite the config layer to use QSettings
  1. Rewrite the path+file layer to use QFile & QDir
  1. Fix current traffic reports list dialog - reports not visible
  1. Support multiuser environments (such as Linux and Windows)
  1. Fix low battery warning still showing when charging