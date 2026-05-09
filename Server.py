import socket
import os
import hashlib

HOST = "0.0.0.0"
PORT = 2222
MAX_FILE_SIZE = 10 * 1024 * 1024

def receive_exact(conn, size):
    data = b""
    while len(data) < size:
        packet = conn.recv(size - len(data))
        if not packet:
            raise ConnectionError("Connection closed early")
        data += packet
    return data

try:
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((HOST, PORT))
    server.listen(1)

    print(f"Server listening on port {PORT}...")

    conn, addr = server.accept()
    print(f"Connected by {addr}")

    name_len = int.from_bytes(receive_exact(conn, 4), "big")
    filename = receive_exact(conn, name_len).decode()
    file_size = int.from_bytes(receive_exact(conn, 8), "big")
    expected_hash = receive_exact(conn, 64).decode()

    if file_size > MAX_FILE_SIZE:
        raise ValueError("File is larger than 10 MB")

    new_name = "received_" + os.path.basename(filename)
    hasher = hashlib.sha256()

    with open(new_name, "wb") as f:
        received = 0
        while received < file_size:
            chunk = conn.recv(min(4096, file_size - received))
            if not chunk:
                raise ConnectionError("Connection lost")
            f.write(chunk)
            hasher.update(chunk)
            received += len(chunk)

    if hasher.hexdigest() == expected_hash:
        print(f"File received successfully as {new_name}")
        print("Checksum verified.")
    else:
        print("Checksum mismatch.")

except Exception as e:
    print(f"Error: {e}")

finally:
    try:
        conn.close()
    except:
        pass
    try:
        server.close()
    except:
        pass
