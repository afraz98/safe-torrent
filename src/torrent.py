from bencoding import Decoder

class Torrent:
    def __init__(self, torrent_file):
        self.torrent_file = torrent_file
        pass

    def _parse_torrent_file(self):
        with open(self.torrent_file, 'rb') as file:
            meta_info = file.read()
            self.meta_info = Decoder(meta_info).decode()
            print(self.meta_info)
        pass

if __name__ == "__main__":
    torrent = Torrent("../ubuntu-22.04.1-desktop-amd64.iso.torrent")
    torrent._parse_torrent_file()