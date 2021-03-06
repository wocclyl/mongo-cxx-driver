// Copyright 2020 MongoDB Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <bsoncxx/private/libbson.hh>
#include <bsoncxx/types/bson_value/view.hpp>

#include <bsoncxx/config/private/prelude.hh>

namespace bsoncxx {
BSONCXX_INLINE_NAMESPACE_BEGIN

namespace types {
namespace bson_value {

class value::impl {
   public:
    impl(const bson_value_t* value) {
        bson_value_copy(value, &_value);
    }

    ~impl() {
        bson_value_destroy(&_value);
    }

    impl(impl&&) = delete;
    impl operator=(impl&&) = delete;
    impl(const impl&) = delete;
    impl operator=(const impl&) = delete;

    bson_value::view view() const noexcept {
        return bson_value::view{(void*)&_value};
    }

    bson_value_t _value;
};

}  // namespace bson_value
}  // namespace types

BSONCXX_INLINE_NAMESPACE_END
}  // namespace bsoncx

#include <bsoncxx/config/private/postlude.hh>
