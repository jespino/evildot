from contextlib import contextmanager
import _evildot


def patch():
    _evildot.patch()


def unpatch():
    _evildot.unpatch()


@contextmanager
def evildot():
    _evildot.patch()
    yield
    _evildot.unpatch()
