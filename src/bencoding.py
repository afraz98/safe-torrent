class Decoder:
    integer_identifier = b'i'
    string_identifier = b':'
    end_identifier = b'e'
    list_identifier = b'l'
    dictionary_identifier = b'd'

    def __init__(self, data):
        self.data = data
        self.index = 0
    
    def decode(self):
        token = self.data[self.index : self.index + 1]

        if token == self.integer_identifier:
            self.index += 1
            return self._parse_integer(self.index)
        elif token in b'0123456789':
            return self._parse_string(self.index)
        elif token == self.list_identifier:
            self.index += 1
            return self._parse_list([])
        elif token == self.dictionary_identifier:
            self.index += 1
            return self._parse_dictionary({})
        elif token == self.end_identifier:
            self.index += 1
        pass
    
    def _find(self, token, start_index):
        self.index = self.data.index(token, start_index)
        return self.data[start_index : self.index]

    def _read_n_bytes(self, n):
        bstr = self.data[self.index : self.index + n]
        self.index += n
        return bstr

    def _parse_integer(self, start_index):
        return int(self._find(self.end_identifier, start_index))

    def _parse_string(self, start_index):
        size = int(self._find(self.string_identifier, start_index))
        self.index += 1
        return self._read_n_bytes(size)

    def _parse_list(self, list):
        if self.index >= len(self.data)-1 or self.data[self.index : self.index + 1] == self.end_identifier:
            return list
        list.append(self.decode())
        return self._parse_list(list)
    
    def _parse_dictionary(self, dictionary):
        if self.index >= len(self.data)-1 or self.data[self.index : self.index + 1] == self.end_identifier:
            return dictionary
        key = self.decode()
        value = self.decode()
        dictionary[key] = value
        return self._parse_dictionary(dictionary)


