import socket
import os
import hashlib
import sys

PORT = 2222
MAX_FILE_SIZE = 10 * 1024 * 1024

def checksum_file(filename):
    hasher = hashlib.sha256()
    with open(filename, "rb") as f:
        while True:
            chunk = f.read(4096)
            if not chunk:
                break
            hasher.update(chunk)
    return hasher.hexdigest()

if len(sys.argv) != 3:
    print("Usage: python3 client.py <server_private_ip> <filename>")
    sys.exit(1)

server_ip = sys.argv[1]
filename = sys.argv[2]

try:
    if not os.path.exists(filename):
        raise FileNotFoundError("File not found")

    file_size = os.path.getsize(filename)

    if file_size > MAX_FILE_SIZE:
        raise ValueError("File is larger than 10 MB")

    file_hash = checksum_file(filename)

    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect((server_ip, PORT))

    filename_bytes = os.path.basename(filename).encode()

    client.sendall(len(filename_bytes).to_bytes(4, "big"))
    client.sendall(filename_bytes)
    client.sendall(file_size.to_bytes(8, "big"))
    client.sendall(file_hash.encode())

    with open(filename, "rb") as f:
        while True:
            chunk = f.read(4096)
            if not chunk:
                break
            client.sendall(chunk)

    print("File sent successfully.")

except FileNotFoundError:
    print("Error: File not found.")

except ConnectionRefusedError:
    print("Error: Connection refused. Make sure server.py is running.")

except TimeoutError:
    print("Error: Connection timed out. Port 2222 may be blocked by AWS.")

except Exception as e:
    print(f"Error: {e}")

finally:
    try:
        client.close()
    except:
        pass
