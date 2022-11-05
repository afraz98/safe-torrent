import unittest

from bencoding import Decoder

class TestDecoder(unittest.TestCase):
    def test_sanity(self):
        self.assertTrue(1 == 1)
        pass

    def test_decode_string(self):
        decoder = Decoder(b'4:abcd')
        self.assertEqual(decoder.decode(), b'abcd')

    def test_decode_integer(self):
        decoder = Decoder(b'i42e')
        self.assertEqual(decoder.decode(), 42)

    def test_decode_list(self):
        decoder = Decoder(b'l4:spam4:eggsi123ee')
        self.assertEqual(decoder.decode(), [b'spam', b'eggs', 123])

    def test_decode_dict(self):
        decoder = Decoder(b'd3:cow3:moo4:spam4:eggse')
        self.assertEqual(decoder.decode(), {b'cow':b'moo', b'spam':b'eggs'})

    def test_decode_dict_list(self):
        decoder = Decoder(b'd3:cow3:moo4:spaml4:spam4:eggsi123eee')
        self.assertEqual(decoder.decode(), {b'cow':b'moo', b'spam':[b'spam', b'eggs', 123]})

