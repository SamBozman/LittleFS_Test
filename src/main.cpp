#include "functions.h"

/* You only need to format LittleFS the first time you run a
   test or else use the LITTLEFS plugin to create a partition
   https://github.com/lorol/arduino-esp32littlefs-plugin

   If you test two partitions, you need to use a custom
   partition.csv file, see in the sketch folder */

//#define TWOPART

#define FORMAT_LITTLEFS_IF_FAILED true


void setup()
{
Serial.begin(115200);
#ifdef TWOPART
    if (!LittleFS.begin(FORMAT_LITTLEFS_IF_FAILED, "/lfs2", 5, "part2"))
    {
        Serial.println("part2 Mount Failed");
        return;
    }
    appendFile(LittleFS, "/hello0.txt", "World0!\r\n");
    readFile(LittleFS, "/hello0.txt");
    LittleFS.end();

    Serial.println("Done with part2, work with the first lfs partition...");
#endif

    if (!LittleFS.begin(FORMAT_LITTLEFS_IF_FAILED))
    {
        Serial.println("LittleFS Mount Failed");
        return;
    }
    
}

void loop()
{
}
