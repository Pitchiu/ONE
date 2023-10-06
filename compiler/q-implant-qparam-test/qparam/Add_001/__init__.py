from test_utils import TestCase
from test_utils import gen_random_tensor


class Add_001_Q8(TestCase):
    def __init__(self):
        self.name = _name_

    def generate(self) -> dict:
        json_content = dict()

        # Generate ifm1
        json_content['ifm1'] = gen_random_tensor(
            "uint8",  # dtype_str
            (1),  # scale_shape
            (1),  # zerop_shape
            0)  # quantized_dimension

        # Generate ifm2
        json_content['ifm2'] = gen_random_tensor(
            "uint8",  #dtype_str
            (1),  # scale_shape
            (1),  # zerop_shape
            0,  # quantized_dimension
            (1, 0, 1))  # value_shape

        # Generate ofm
        json_content['ofm'] = gen_random_tensor(
            "uint8",  # dtype_str
            (1),  # scale_shape
            (1),  # zerop_shape
            0)  # quantized_dimension

        return json_content


_name_ = 'Add_001_Q8'

_test_case_ = Add_001_Q8()
