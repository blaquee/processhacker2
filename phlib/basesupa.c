/*
 * Process Hacker -
 *   base support functions (auto-dereference enabled)
 *
 * Copyright (C) 2010 wj32
 *
 * This file is part of Process Hacker.
 *
 * Process Hacker is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Process Hacker is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Process Hacker.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <phbase.h>

PPH_STRING PhaCreateString(
    _In_ PWSTR Buffer
    )
{
    return PH_AUTO(PhCreateString(Buffer));
}

PPH_STRING PhaCreateStringEx(
    _In_opt_ PWSTR Buffer,
    _In_ SIZE_T Length
    )
{
    return PH_AUTO(PhCreateStringEx(Buffer, Length));
}

PPH_STRING PhaDuplicateString(
    _In_ PPH_STRING String
    )
{
    return PH_AUTO(PhDuplicateString(String));
}

PPH_STRING PhaConcatStrings(
    _In_ ULONG Count,
    ...
    )
{
    va_list argptr;

    va_start(argptr, Count);

    return PH_AUTO(PhConcatStrings_V(Count, argptr));
}

PPH_STRING PhaConcatStrings2(
    _In_ PWSTR String1,
    _In_ PWSTR String2
    )
{
    return PH_AUTO(PhConcatStrings2(String1, String2));
}

PPH_STRING PhaFormatString(
    _In_ _Printf_format_string_ PWSTR Format,
    ...
    )
{
    va_list argptr;

    va_start(argptr, Format);

    return PH_AUTO(PhFormatString_V(Format, argptr));
}

PPH_STRING PhaLowerString(
    _In_ PPH_STRING String
    )
{
    PPH_STRING newString;

    newString = PhaDuplicateString(String);
    _wcslwr(newString->Buffer);

    return newString;
}

PPH_STRING PhaUpperString(
    _In_ PPH_STRING String
    )
{
    PPH_STRING newString;

    newString = PhaDuplicateString(String);
    _wcsupr(newString->Buffer);

    return newString;
}

PPH_STRING PhaSubstring(
    _In_ PPH_STRING String,
    _In_ SIZE_T StartIndex,
    _In_ SIZE_T Count
    )
{
    return PH_AUTO(PhSubstring(String, StartIndex, Count));
}
