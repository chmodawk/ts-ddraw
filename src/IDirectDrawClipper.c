/*
 * Copyright (c) 2013 Toni Spets <toni.spets@iki.fi>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include "main.h"
#include "IDirectDrawClipper.h"

static IDirectDrawClipperImplVtbl Vtbl;

IDirectDrawClipperImpl *IDirectDrawClipperImpl_construct()
{
    IDirectDrawClipperImpl *this = calloc(1, sizeof(IDirectDrawClipperImpl));
    this->lpVtbl = &Vtbl;
    dprintf("IDirectDrawClipper::construct() -> %p\n", this);
    this->ref++;
    return this;
}

static HRESULT __stdcall _QueryInterface(IDirectDrawClipperImpl *this, REFIID riid, void **obj)
{
    HRESULT ret = DDERR_UNSUPPORTED;

    if (PROXY)
    {
        ret = IDirectDrawClipper_QueryInterface(this->real, riid, obj);
    }

    dprintf("IDirectDrawClipper::QueryInterface(this=%p, riid=%08X, obj=%p) -> %08X\n", this, (unsigned int)riid, obj, (int)ret);
    return ret;
}

static ULONG __stdcall _AddRef(IDirectDrawClipperImpl *this)
{
    ULONG ret = ++this->ref;

    if (PROXY)
    {
        ret = IDirectDrawClipper_AddRef(this->real);
    }

    dprintf("IDirectDrawClipper::AddRef(this=%p) -> %08X\n", this, (int)ret);

    return ret;
}

static ULONG __stdcall _Release(IDirectDrawClipperImpl *this)
{
    ULONG ret = --this->ref;

    if (PROXY)
    {
        ret = IDirectDrawClipper_Release(this->real);
    }
    else
    {
        if (ret == 0)
        {
            free(this);
        }
    }

    dprintf("IDirectDrawClipper::Release(this=%p) -> %08X\n", this, (int)ret);
    return ret;
}

static HRESULT __stdcall _GetClipList(IDirectDrawClipperImpl *this, LPRECT lpRect, LPRGNDATA lpClipList, LPDWORD lpdwSize)
{
    HRESULT ret = DDERR_UNSUPPORTED;

    if (PROXY)
    {
        ret = IDirectDrawClipper_GetClipList(this->real, lpRect, lpClipList, lpdwSize);
    }

    dprintf("IDirectDrawClipper::GetClipList(this=%p, lpRect=%p, lpClipList=%p, lpdwSize=%p) -> %08X\n", this, lpRect, lpClipList, lpdwSize, (int)ret);
    return ret;
}

static HRESULT __stdcall _GetHWnd(IDirectDrawClipperImpl *this, HWND FAR *lphWnd)
{
    HRESULT ret = DDERR_UNSUPPORTED;

    if (PROXY)
    {
        ret = IDirectDrawClipper_GetHWnd(this->real, lphWnd);
    }

    dprintf("IDirectDrawClipper::GetHWnd(this=%p, lphWnd=%p) -> %08X\n", this, lphWnd, (int)ret);
    return ret;
}

static HRESULT __stdcall _Initialize(IDirectDrawClipperImpl *this, LPDIRECTDRAW lpDD, DWORD dwFlags)
{
    HRESULT ret = DDERR_UNSUPPORTED;

    if (PROXY)
    {
        ret = IDirectDrawClipper_Initialize(this->real, lpDD, dwFlags);
    }

    dprintf("IDirectDrawClipper::Initialize(this=%p, lpDD=%p, dwFlags=%08X) -> %08X\n", this, lpDD, (int)dwFlags, (int)ret);
    return ret;
}

static HRESULT __stdcall _IsClipListChanged(IDirectDrawClipperImpl *this, BOOL FAR *lpbChanged)
{
    HRESULT ret = DDERR_UNSUPPORTED;

    if (PROXY)
    {
        ret = IDirectDrawClipper_IsClipListChanged(this->real, lpbChanged);
    }

    dprintf("IDirectDrawClipper::IsClipListChanged(this=%p, lpbChanged=%p) -> %08X\n", this, lpbChanged, (int)ret);
    return ret;
}

static HRESULT __stdcall _SetClipList(IDirectDrawClipperImpl *this, LPRGNDATA lpClipList, DWORD dwFlags)
{
    HRESULT ret = DDERR_UNSUPPORTED;

    if (PROXY)
    {
        ret = IDirectDrawClipper_SetClipList(this->real, lpClipList, dwFlags);
    }

    dprintf("IDirectDrawClipper::SetClipList(this=%p, lpClipList=%p, dwFlags=%08X) -> %08X\n", this, lpClipList, (int)dwFlags, (int)ret);
    return ret;
}

static HRESULT __stdcall _SetHWnd(IDirectDrawClipperImpl *this, DWORD dwFlags, HWND hWnd)
{
    HRESULT ret = DDERR_UNSUPPORTED;

    if (PROXY)
    {
        ret = IDirectDrawClipper_SetHWnd(this->real, dwFlags, hWnd);
    }

    dprintf("IDirectDrawClipper::SetHWnd(this=%p, dwFlags=%08X, hWnd=%08X) -> %08X\n", this, (int)dwFlags, (int)hWnd, (int)ret);
    return ret;
}

static struct IDirectDrawClipperImplVtbl Vtbl =
{
    /* IUnknown */
    _QueryInterface,
    _AddRef,
    _Release,
    /* IDirectDrawClipper */
    _GetClipList,
    _GetHWnd,
    _Initialize,
    _IsClipListChanged,
    _SetClipList,
    _SetHWnd
};
