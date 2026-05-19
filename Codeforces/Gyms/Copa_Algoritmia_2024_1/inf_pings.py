from ping3 import ping
import time

def send_ping(server: str, packet_size: int):
    try:
        # Send the ping
        response_time = ping(server, size=packet_size, timeout=4)
        
        if response_time is None:
            print(f"Ping to {server} timed out.")
        else:
            print(f"Ping to {server} successful! Response time: {response_time:.2f} ms")
    except Exception as e:
        print(f"An error occurred while pinging {server}: {e}")

if __name__ == "__main__":
    target_server = '199.26.84.130'
    packet_size = 1450
    
    print(f"\nStarting continuous ping to {target_server} with packet size {packet_size} bytes. Press Ctrl+C to stop.\n")
    
    while True:
        send_ping(target_server, packet_size)
        #time.sleep(1)  # Pause for 1 second between pings
