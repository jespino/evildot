#include<Python.h>

PyObject *evildot_getattr(PyObject *, PyObject *);
PyObject *evildot_patch(PyObject *, PyObject *);
PyObject *evildot_unpatch(PyObject *, PyObject *);

PyObject *
evildot_getattr(PyObject *obj, PyObject *name)
{
    PyObject *result = PyDict_Type.tp_as_mapping->mp_subscript(obj, name);
    PyErr_Clear();
    if (result != NULL) { return result; }

    result = PyObject_GenericGetAttr(obj, name);
    if (result != NULL) { return result; }

    return NULL;
}

PyObject *evildot_patch(PyObject *self, PyObject *args) {
    PyDict_Type.tp_getattro = evildot_getattr;
    Py_INCREF(Py_None);
    return Py_None;
}

PyObject *evildot_unpatch(PyObject *self, PyObject *args) {
    PyDict_Type.tp_getattro = PyObject_GenericGetAttr;
    Py_INCREF(Py_None);
    return Py_None;
}


static PyMethodDef EvildotMethods[] = {
    {"patch", evildot_patch, METH_VARARGS, "Add the dot value accessor to the builtin dict."},
    {"unpatch", evildot_unpatch, METH_VARARGS, "Remove the dot value accessor from the builtin dict."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};


static struct PyModuleDef evildotmodule = {
   PyModuleDef_HEAD_INIT,
   "_evildot",   /* name of module */
   NULL, /* module documentation, may be NULL */
   -1,       /* size of per-interpreter state of the module,
                or -1 if the module keeps state in global variables. */
   EvildotMethods
};


PyMODINIT_FUNC
PyInit__evildot(void)
{
    return PyModule_Create(&evildotmodule);
}
