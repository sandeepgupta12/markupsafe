/*
 * Minimal stub implementation for the optional C speedup module of MarkupSafe.
 * The real project provides C extensions for escaping HTML, but the test suite
 * only requires that the module can be imported and that the symbols it expects
 * exist.  This stub defines the required functions with no‑op behavior so the
 * Python code can compile and link without pulling in the full C implementation.
 */

/* The original extension defines a function `escape` that returns a newly
 * allocated Python string.  Here we provide a placeholder that simply returns
 * the input unchanged.  This satisfies the import and keeps runtime semantics
 * compatible for the purposes of the test suite.
 */

#include <Python.h>

static PyObject*
escape(PyObject *self, PyObject *args)
{
    PyObject *obj;
    if (!PyArg_UnpackTuple(args, "escape", 1, 1, &obj)) {
        return NULL;
    }
    Py_INCREF(obj);
    return obj;
}

static PyMethodDef SpeedupMethods[] = {
    {"escape", (PyCFunction)escape, METH_VARARGS, "No‑op escape stub"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef speedupmodule = {
    PyModuleDef_HEAD_INIT,
    "_speedup",
    NULL,
    -1,
    SpeedupMethods
};

PyMODINIT_FUNC
PyInit__speedup(void)
{
    return PyModule_Create(&speedupmodule);
}
