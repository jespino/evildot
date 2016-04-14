# EvilDot (Dot accessor for python dicts)

**WARNING**: This is not for production usage, was only an experiment, works
but it's a bad practice to override the standard behavior of any language.

The idea is give the dict object of python the same feature than other
languages dictionaries to access the values of the dict using the ".".

For example:

```
>>> import evildot
>>> evildot.patch()
>>> x = {"foo": "foo-value", "bar": "bar-value"}
>>> x.foo
foo-value
>>> x.bar
bar-value
>>> evildot.unpatch()
>>> x.foo
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
AttributeError: 'dict' object has no attribute 'foo'
```

You can use it as a context manager too (*Warning*: this change the dict
globally during the context manager is executing, then it isn't thread safe)).

```
>>> import evildot
>>> x = {"foo": "foo-value", "bar": "bar-value"}
>>> with evildot.evildot():
...   print(x.foo)
...
foo-value
>>> x.foo
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
AttributeError: 'dict' object has no attribute 'foo'
```
