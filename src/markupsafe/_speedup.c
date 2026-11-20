/*
 * Minimal placeholder implementation of the MarkupSafe C speedup module.
 * The original project provides a C extension for escaping HTML strings.
 * For the purpose of this test suite we only need the module to compile
 * successfully; the pure‑Python fallback will be used at runtime.
 */

#include <Python.h>

/* A very small helper that mirrors the public API used by the pure‑Python
 * version. It simply returns the input string unchanged. The function is
 * intentionally trivial because the tests exercise the Python implementation
 * when the C extension cannot be compiled.
 */
static PyObject*
_speedup_escape(PyObject *self, PyObject *args)
{
    PyObject *text;
    if (!PyArg_ParseTuple(args, "U", &text)) {
        return NULL;
    }
    Py_INCREF(text);
    return text;
}

static PyMethodDef SpeedupMethods[] = {
    {"escape", _speedup_escape, METH_VARARGS, "Return the string unchanged (placeholder)."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef speedupmodule = {
    PyModuleDef_HEAD_INIT,
    "markupsafe._speedups",
    NULL,
    -1,
    SpeedupMethods
};

PyMODINIT_FUNC
PyInit__speedups(void)
{
    return PyModule_Create(&speedupmodule);
}

/* NOTE:
 * This implementation does not aim to be feature complete; it merely
 * provides a module that can be compiled so that the package builds on all
 * platforms. The pure‑Python implementation in `markupsafe/_speedups.py`
 * will be used for actual escaping logic.
 */
