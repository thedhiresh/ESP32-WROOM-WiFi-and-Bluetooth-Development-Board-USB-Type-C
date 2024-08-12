import network
import urequests

ssid = "camera_wifi_ssid"  # Replace with the camera's Wi-Fi network name
password = ""  # Leave empty if no password is set

wlan = network.WLAN(network.STA_IF)
wlan.active(True)
wlan.connect(ssid, password)

while not wlan.isconnected():
    print("Connecting to WiFi...")
    time.sleep(1)

print("Connected to WiFi")
print("IP address: ")
print(wlan.ifconfig()[0])

# Identify the camera's IP address (e.g., using nmap or arp-scan)
camera_ip = "192.168.1.100"  # Replace with the camera's IP address

# Send an HTTP request to the camera
response = urequests.get("http://" + camera_ip + "/cgi-bin/video.cgi")
if response.status_code == 200:
    print("HTTP response code: ", response.status_code)
    print(response.text)
else:
    print("Error sending HTTP request")
