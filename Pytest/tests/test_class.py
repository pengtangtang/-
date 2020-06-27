def test_add():
    x = 3
    y = 4
    assert x == y,"test failed because x = :" + str(x) + "y = " + str(y)

class TestClass(object):
    def test_one(self):
        x = "this"
        assert 'h' in x

    def three_test(self):
        x = "check"
        assert hasattr(x,'check')

    def test_add(self):
        x = 3
        y = 4
        assert x == y,"test failed because x = :" + str(x) + "y = " + str(y)
        
