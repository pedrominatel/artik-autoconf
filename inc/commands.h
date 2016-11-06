#define SCAN_WIFI_NETWORKS                  "/usr/sbin/wpa_cli scan"
#define LIST_WIFI_NETWORKS                  "/usr/sbin/wpa_cli scan_results"
#define LIST_WIFI_ONFIGURED_NETWORKS        "/usr/sbin/wpa_cli list_networks"

#define START_DHCP_CLIENT                   "/usr/sbin/dhclient wlan0"

#define PING_TEST                           "/usr/bin/ping -c 5 google.com"
#define REBOOT                              "reboot"
#define RESTART_WPA                         "/usr/bin/systemctl restart wpa_supplicant "

#define INSTALL_ARDUINO                     "/usr/bin/curl downloads.arduino.cc/libArduino/install_artik_prereq.sh | sh"
//

// wpa_passphrase MyAP abcd1234  >> /etc/wpa_supplicant/wpa_supplicant.conf


#define NETWORK_STATUS                      "/usr/sbin/ifconfig"
