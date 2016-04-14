from distutils.core import setup, Extension

setup(
    name='evildot',
    version='0.0.1',
    description='Access to dictionary values using dot notation',
    keywords = 'evil, dot, dict',
    author='Jesús Espino',
    author_email='jespinog@gmail.com',
    url='https://github.com/jespino/evildot',
    license = 'BSD',
    ext_modules=[Extension("_evildot", ["src/evildot.c"])],
    packages=['evildot'],
    package_dir={'evildot': 'src/evildot'},
    classifiers = [
        "Programming Language :: Python",
        'Development Status :: 4 - Beta',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: BSD License',
        'Operating System :: OS Independent',
        'Programming Language :: Python',
    ]
)
