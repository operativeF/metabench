#define METABENCH
#include <cstddef>
#include <type_traits>

#if defined(METABENCH)

template <typename T, typename U = typename std::remove_reference<T>::type>
struct decay {
    typedef typename std::remove_cv<U>::type type;
};

template <typename T, typename U>
struct decay<T, U[]> { typedef U* type; };
template <typename T, typename U, std::size_t N>
struct decay<T, U[N]> { typedef U* type; };

template <typename T, typename R, typename ...A>
struct decay<T, R(A...)> { typedef R(*type)(A...); };
template <typename T, typename R, typename ...A>
struct decay<T, R(A..., ...)> { typedef R(*type)(A..., ...); };


    struct T0 { };
    typedef decay<T0>::type             foo1_0;
    typedef decay<T0&>::type            foo2_0;
    typedef decay<T0&&>::type           foo3_0;
    typedef decay<T0 const>::type       foo4_0;
    typedef decay<T0 volatile>::type    foo5_0;
    typedef decay<T0 [3]>::type         foo6_0;
    struct T1 { };
    typedef decay<T1>::type             foo1_1;
    typedef decay<T1&>::type            foo2_1;
    typedef decay<T1&&>::type           foo3_1;
    typedef decay<T1 const>::type       foo4_1;
    typedef decay<T1 volatile>::type    foo5_1;
    typedef decay<T1 [3]>::type         foo6_1;
    struct T2 { };
    typedef decay<T2>::type             foo1_2;
    typedef decay<T2&>::type            foo2_2;
    typedef decay<T2&&>::type           foo3_2;
    typedef decay<T2 const>::type       foo4_2;
    typedef decay<T2 volatile>::type    foo5_2;
    typedef decay<T2 [3]>::type         foo6_2;
    struct T3 { };
    typedef decay<T3>::type             foo1_3;
    typedef decay<T3&>::type            foo2_3;
    typedef decay<T3&&>::type           foo3_3;
    typedef decay<T3 const>::type       foo4_3;
    typedef decay<T3 volatile>::type    foo5_3;
    typedef decay<T3 [3]>::type         foo6_3;
    struct T4 { };
    typedef decay<T4>::type             foo1_4;
    typedef decay<T4&>::type            foo2_4;
    typedef decay<T4&&>::type           foo3_4;
    typedef decay<T4 const>::type       foo4_4;
    typedef decay<T4 volatile>::type    foo5_4;
    typedef decay<T4 [3]>::type         foo6_4;
    struct T5 { };
    typedef decay<T5>::type             foo1_5;
    typedef decay<T5&>::type            foo2_5;
    typedef decay<T5&&>::type           foo3_5;
    typedef decay<T5 const>::type       foo4_5;
    typedef decay<T5 volatile>::type    foo5_5;
    typedef decay<T5 [3]>::type         foo6_5;
    struct T6 { };
    typedef decay<T6>::type             foo1_6;
    typedef decay<T6&>::type            foo2_6;
    typedef decay<T6&&>::type           foo3_6;
    typedef decay<T6 const>::type       foo4_6;
    typedef decay<T6 volatile>::type    foo5_6;
    typedef decay<T6 [3]>::type         foo6_6;
    struct T7 { };
    typedef decay<T7>::type             foo1_7;
    typedef decay<T7&>::type            foo2_7;
    typedef decay<T7&&>::type           foo3_7;
    typedef decay<T7 const>::type       foo4_7;
    typedef decay<T7 volatile>::type    foo5_7;
    typedef decay<T7 [3]>::type         foo6_7;
    struct T8 { };
    typedef decay<T8>::type             foo1_8;
    typedef decay<T8&>::type            foo2_8;
    typedef decay<T8&&>::type           foo3_8;
    typedef decay<T8 const>::type       foo4_8;
    typedef decay<T8 volatile>::type    foo5_8;
    typedef decay<T8 [3]>::type         foo6_8;
    struct T9 { };
    typedef decay<T9>::type             foo1_9;
    typedef decay<T9&>::type            foo2_9;
    typedef decay<T9&&>::type           foo3_9;
    typedef decay<T9 const>::type       foo4_9;
    typedef decay<T9 volatile>::type    foo5_9;
    typedef decay<T9 [3]>::type         foo6_9;
    struct T10 { };
    typedef decay<T10>::type             foo1_10;
    typedef decay<T10&>::type            foo2_10;
    typedef decay<T10&&>::type           foo3_10;
    typedef decay<T10 const>::type       foo4_10;
    typedef decay<T10 volatile>::type    foo5_10;
    typedef decay<T10 [3]>::type         foo6_10;
    struct T11 { };
    typedef decay<T11>::type             foo1_11;
    typedef decay<T11&>::type            foo2_11;
    typedef decay<T11&&>::type           foo3_11;
    typedef decay<T11 const>::type       foo4_11;
    typedef decay<T11 volatile>::type    foo5_11;
    typedef decay<T11 [3]>::type         foo6_11;
    struct T12 { };
    typedef decay<T12>::type             foo1_12;
    typedef decay<T12&>::type            foo2_12;
    typedef decay<T12&&>::type           foo3_12;
    typedef decay<T12 const>::type       foo4_12;
    typedef decay<T12 volatile>::type    foo5_12;
    typedef decay<T12 [3]>::type         foo6_12;
    struct T13 { };
    typedef decay<T13>::type             foo1_13;
    typedef decay<T13&>::type            foo2_13;
    typedef decay<T13&&>::type           foo3_13;
    typedef decay<T13 const>::type       foo4_13;
    typedef decay<T13 volatile>::type    foo5_13;
    typedef decay<T13 [3]>::type         foo6_13;
    struct T14 { };
    typedef decay<T14>::type             foo1_14;
    typedef decay<T14&>::type            foo2_14;
    typedef decay<T14&&>::type           foo3_14;
    typedef decay<T14 const>::type       foo4_14;
    typedef decay<T14 volatile>::type    foo5_14;
    typedef decay<T14 [3]>::type         foo6_14;
    struct T15 { };
    typedef decay<T15>::type             foo1_15;
    typedef decay<T15&>::type            foo2_15;
    typedef decay<T15&&>::type           foo3_15;
    typedef decay<T15 const>::type       foo4_15;
    typedef decay<T15 volatile>::type    foo5_15;
    typedef decay<T15 [3]>::type         foo6_15;
    struct T16 { };
    typedef decay<T16>::type             foo1_16;
    typedef decay<T16&>::type            foo2_16;
    typedef decay<T16&&>::type           foo3_16;
    typedef decay<T16 const>::type       foo4_16;
    typedef decay<T16 volatile>::type    foo5_16;
    typedef decay<T16 [3]>::type         foo6_16;
    struct T17 { };
    typedef decay<T17>::type             foo1_17;
    typedef decay<T17&>::type            foo2_17;
    typedef decay<T17&&>::type           foo3_17;
    typedef decay<T17 const>::type       foo4_17;
    typedef decay<T17 volatile>::type    foo5_17;
    typedef decay<T17 [3]>::type         foo6_17;
    struct T18 { };
    typedef decay<T18>::type             foo1_18;
    typedef decay<T18&>::type            foo2_18;
    typedef decay<T18&&>::type           foo3_18;
    typedef decay<T18 const>::type       foo4_18;
    typedef decay<T18 volatile>::type    foo5_18;
    typedef decay<T18 [3]>::type         foo6_18;
    struct T19 { };
    typedef decay<T19>::type             foo1_19;
    typedef decay<T19&>::type            foo2_19;
    typedef decay<T19&&>::type           foo3_19;
    typedef decay<T19 const>::type       foo4_19;
    typedef decay<T19 volatile>::type    foo5_19;
    typedef decay<T19 [3]>::type         foo6_19;
    struct T20 { };
    typedef decay<T20>::type             foo1_20;
    typedef decay<T20&>::type            foo2_20;
    typedef decay<T20&&>::type           foo3_20;
    typedef decay<T20 const>::type       foo4_20;
    typedef decay<T20 volatile>::type    foo5_20;
    typedef decay<T20 [3]>::type         foo6_20;
    struct T21 { };
    typedef decay<T21>::type             foo1_21;
    typedef decay<T21&>::type            foo2_21;
    typedef decay<T21&&>::type           foo3_21;
    typedef decay<T21 const>::type       foo4_21;
    typedef decay<T21 volatile>::type    foo5_21;
    typedef decay<T21 [3]>::type         foo6_21;
    struct T22 { };
    typedef decay<T22>::type             foo1_22;
    typedef decay<T22&>::type            foo2_22;
    typedef decay<T22&&>::type           foo3_22;
    typedef decay<T22 const>::type       foo4_22;
    typedef decay<T22 volatile>::type    foo5_22;
    typedef decay<T22 [3]>::type         foo6_22;
    struct T23 { };
    typedef decay<T23>::type             foo1_23;
    typedef decay<T23&>::type            foo2_23;
    typedef decay<T23&&>::type           foo3_23;
    typedef decay<T23 const>::type       foo4_23;
    typedef decay<T23 volatile>::type    foo5_23;
    typedef decay<T23 [3]>::type         foo6_23;
    struct T24 { };
    typedef decay<T24>::type             foo1_24;
    typedef decay<T24&>::type            foo2_24;
    typedef decay<T24&&>::type           foo3_24;
    typedef decay<T24 const>::type       foo4_24;
    typedef decay<T24 volatile>::type    foo5_24;
    typedef decay<T24 [3]>::type         foo6_24;
    struct T25 { };
    typedef decay<T25>::type             foo1_25;
    typedef decay<T25&>::type            foo2_25;
    typedef decay<T25&&>::type           foo3_25;
    typedef decay<T25 const>::type       foo4_25;
    typedef decay<T25 volatile>::type    foo5_25;
    typedef decay<T25 [3]>::type         foo6_25;
    struct T26 { };
    typedef decay<T26>::type             foo1_26;
    typedef decay<T26&>::type            foo2_26;
    typedef decay<T26&&>::type           foo3_26;
    typedef decay<T26 const>::type       foo4_26;
    typedef decay<T26 volatile>::type    foo5_26;
    typedef decay<T26 [3]>::type         foo6_26;
    struct T27 { };
    typedef decay<T27>::type             foo1_27;
    typedef decay<T27&>::type            foo2_27;
    typedef decay<T27&&>::type           foo3_27;
    typedef decay<T27 const>::type       foo4_27;
    typedef decay<T27 volatile>::type    foo5_27;
    typedef decay<T27 [3]>::type         foo6_27;
    struct T28 { };
    typedef decay<T28>::type             foo1_28;
    typedef decay<T28&>::type            foo2_28;
    typedef decay<T28&&>::type           foo3_28;
    typedef decay<T28 const>::type       foo4_28;
    typedef decay<T28 volatile>::type    foo5_28;
    typedef decay<T28 [3]>::type         foo6_28;
    struct T29 { };
    typedef decay<T29>::type             foo1_29;
    typedef decay<T29&>::type            foo2_29;
    typedef decay<T29&&>::type           foo3_29;
    typedef decay<T29 const>::type       foo4_29;
    typedef decay<T29 volatile>::type    foo5_29;
    typedef decay<T29 [3]>::type         foo6_29;
    struct T30 { };
    typedef decay<T30>::type             foo1_30;
    typedef decay<T30&>::type            foo2_30;
    typedef decay<T30&&>::type           foo3_30;
    typedef decay<T30 const>::type       foo4_30;
    typedef decay<T30 volatile>::type    foo5_30;
    typedef decay<T30 [3]>::type         foo6_30;
    struct T31 { };
    typedef decay<T31>::type             foo1_31;
    typedef decay<T31&>::type            foo2_31;
    typedef decay<T31&&>::type           foo3_31;
    typedef decay<T31 const>::type       foo4_31;
    typedef decay<T31 volatile>::type    foo5_31;
    typedef decay<T31 [3]>::type         foo6_31;
    struct T32 { };
    typedef decay<T32>::type             foo1_32;
    typedef decay<T32&>::type            foo2_32;
    typedef decay<T32&&>::type           foo3_32;
    typedef decay<T32 const>::type       foo4_32;
    typedef decay<T32 volatile>::type    foo5_32;
    typedef decay<T32 [3]>::type         foo6_32;
    struct T33 { };
    typedef decay<T33>::type             foo1_33;
    typedef decay<T33&>::type            foo2_33;
    typedef decay<T33&&>::type           foo3_33;
    typedef decay<T33 const>::type       foo4_33;
    typedef decay<T33 volatile>::type    foo5_33;
    typedef decay<T33 [3]>::type         foo6_33;
    struct T34 { };
    typedef decay<T34>::type             foo1_34;
    typedef decay<T34&>::type            foo2_34;
    typedef decay<T34&&>::type           foo3_34;
    typedef decay<T34 const>::type       foo4_34;
    typedef decay<T34 volatile>::type    foo5_34;
    typedef decay<T34 [3]>::type         foo6_34;
    struct T35 { };
    typedef decay<T35>::type             foo1_35;
    typedef decay<T35&>::type            foo2_35;
    typedef decay<T35&&>::type           foo3_35;
    typedef decay<T35 const>::type       foo4_35;
    typedef decay<T35 volatile>::type    foo5_35;
    typedef decay<T35 [3]>::type         foo6_35;
    struct T36 { };
    typedef decay<T36>::type             foo1_36;
    typedef decay<T36&>::type            foo2_36;
    typedef decay<T36&&>::type           foo3_36;
    typedef decay<T36 const>::type       foo4_36;
    typedef decay<T36 volatile>::type    foo5_36;
    typedef decay<T36 [3]>::type         foo6_36;
    struct T37 { };
    typedef decay<T37>::type             foo1_37;
    typedef decay<T37&>::type            foo2_37;
    typedef decay<T37&&>::type           foo3_37;
    typedef decay<T37 const>::type       foo4_37;
    typedef decay<T37 volatile>::type    foo5_37;
    typedef decay<T37 [3]>::type         foo6_37;
    struct T38 { };
    typedef decay<T38>::type             foo1_38;
    typedef decay<T38&>::type            foo2_38;
    typedef decay<T38&&>::type           foo3_38;
    typedef decay<T38 const>::type       foo4_38;
    typedef decay<T38 volatile>::type    foo5_38;
    typedef decay<T38 [3]>::type         foo6_38;
    struct T39 { };
    typedef decay<T39>::type             foo1_39;
    typedef decay<T39&>::type            foo2_39;
    typedef decay<T39&&>::type           foo3_39;
    typedef decay<T39 const>::type       foo4_39;
    typedef decay<T39 volatile>::type    foo5_39;
    typedef decay<T39 [3]>::type         foo6_39;
    struct T40 { };
    typedef decay<T40>::type             foo1_40;
    typedef decay<T40&>::type            foo2_40;
    typedef decay<T40&&>::type           foo3_40;
    typedef decay<T40 const>::type       foo4_40;
    typedef decay<T40 volatile>::type    foo5_40;
    typedef decay<T40 [3]>::type         foo6_40;
    struct T41 { };
    typedef decay<T41>::type             foo1_41;
    typedef decay<T41&>::type            foo2_41;
    typedef decay<T41&&>::type           foo3_41;
    typedef decay<T41 const>::type       foo4_41;
    typedef decay<T41 volatile>::type    foo5_41;
    typedef decay<T41 [3]>::type         foo6_41;
    struct T42 { };
    typedef decay<T42>::type             foo1_42;
    typedef decay<T42&>::type            foo2_42;
    typedef decay<T42&&>::type           foo3_42;
    typedef decay<T42 const>::type       foo4_42;
    typedef decay<T42 volatile>::type    foo5_42;
    typedef decay<T42 [3]>::type         foo6_42;
    struct T43 { };
    typedef decay<T43>::type             foo1_43;
    typedef decay<T43&>::type            foo2_43;
    typedef decay<T43&&>::type           foo3_43;
    typedef decay<T43 const>::type       foo4_43;
    typedef decay<T43 volatile>::type    foo5_43;
    typedef decay<T43 [3]>::type         foo6_43;
    struct T44 { };
    typedef decay<T44>::type             foo1_44;
    typedef decay<T44&>::type            foo2_44;
    typedef decay<T44&&>::type           foo3_44;
    typedef decay<T44 const>::type       foo4_44;
    typedef decay<T44 volatile>::type    foo5_44;
    typedef decay<T44 [3]>::type         foo6_44;
    struct T45 { };
    typedef decay<T45>::type             foo1_45;
    typedef decay<T45&>::type            foo2_45;
    typedef decay<T45&&>::type           foo3_45;
    typedef decay<T45 const>::type       foo4_45;
    typedef decay<T45 volatile>::type    foo5_45;
    typedef decay<T45 [3]>::type         foo6_45;
    struct T46 { };
    typedef decay<T46>::type             foo1_46;
    typedef decay<T46&>::type            foo2_46;
    typedef decay<T46&&>::type           foo3_46;
    typedef decay<T46 const>::type       foo4_46;
    typedef decay<T46 volatile>::type    foo5_46;
    typedef decay<T46 [3]>::type         foo6_46;
    struct T47 { };
    typedef decay<T47>::type             foo1_47;
    typedef decay<T47&>::type            foo2_47;
    typedef decay<T47&&>::type           foo3_47;
    typedef decay<T47 const>::type       foo4_47;
    typedef decay<T47 volatile>::type    foo5_47;
    typedef decay<T47 [3]>::type         foo6_47;
    struct T48 { };
    typedef decay<T48>::type             foo1_48;
    typedef decay<T48&>::type            foo2_48;
    typedef decay<T48&&>::type           foo3_48;
    typedef decay<T48 const>::type       foo4_48;
    typedef decay<T48 volatile>::type    foo5_48;
    typedef decay<T48 [3]>::type         foo6_48;
    struct T49 { };
    typedef decay<T49>::type             foo1_49;
    typedef decay<T49&>::type            foo2_49;
    typedef decay<T49&&>::type           foo3_49;
    typedef decay<T49 const>::type       foo4_49;
    typedef decay<T49 volatile>::type    foo5_49;
    typedef decay<T49 [3]>::type         foo6_49;
    struct T50 { };
    typedef decay<T50>::type             foo1_50;
    typedef decay<T50&>::type            foo2_50;
    typedef decay<T50&&>::type           foo3_50;
    typedef decay<T50 const>::type       foo4_50;
    typedef decay<T50 volatile>::type    foo5_50;
    typedef decay<T50 [3]>::type         foo6_50;
    struct T51 { };
    typedef decay<T51>::type             foo1_51;
    typedef decay<T51&>::type            foo2_51;
    typedef decay<T51&&>::type           foo3_51;
    typedef decay<T51 const>::type       foo4_51;
    typedef decay<T51 volatile>::type    foo5_51;
    typedef decay<T51 [3]>::type         foo6_51;
    struct T52 { };
    typedef decay<T52>::type             foo1_52;
    typedef decay<T52&>::type            foo2_52;
    typedef decay<T52&&>::type           foo3_52;
    typedef decay<T52 const>::type       foo4_52;
    typedef decay<T52 volatile>::type    foo5_52;
    typedef decay<T52 [3]>::type         foo6_52;
    struct T53 { };
    typedef decay<T53>::type             foo1_53;
    typedef decay<T53&>::type            foo2_53;
    typedef decay<T53&&>::type           foo3_53;
    typedef decay<T53 const>::type       foo4_53;
    typedef decay<T53 volatile>::type    foo5_53;
    typedef decay<T53 [3]>::type         foo6_53;
    struct T54 { };
    typedef decay<T54>::type             foo1_54;
    typedef decay<T54&>::type            foo2_54;
    typedef decay<T54&&>::type           foo3_54;
    typedef decay<T54 const>::type       foo4_54;
    typedef decay<T54 volatile>::type    foo5_54;
    typedef decay<T54 [3]>::type         foo6_54;
    struct T55 { };
    typedef decay<T55>::type             foo1_55;
    typedef decay<T55&>::type            foo2_55;
    typedef decay<T55&&>::type           foo3_55;
    typedef decay<T55 const>::type       foo4_55;
    typedef decay<T55 volatile>::type    foo5_55;
    typedef decay<T55 [3]>::type         foo6_55;
    struct T56 { };
    typedef decay<T56>::type             foo1_56;
    typedef decay<T56&>::type            foo2_56;
    typedef decay<T56&&>::type           foo3_56;
    typedef decay<T56 const>::type       foo4_56;
    typedef decay<T56 volatile>::type    foo5_56;
    typedef decay<T56 [3]>::type         foo6_56;
    struct T57 { };
    typedef decay<T57>::type             foo1_57;
    typedef decay<T57&>::type            foo2_57;
    typedef decay<T57&&>::type           foo3_57;
    typedef decay<T57 const>::type       foo4_57;
    typedef decay<T57 volatile>::type    foo5_57;
    typedef decay<T57 [3]>::type         foo6_57;
    struct T58 { };
    typedef decay<T58>::type             foo1_58;
    typedef decay<T58&>::type            foo2_58;
    typedef decay<T58&&>::type           foo3_58;
    typedef decay<T58 const>::type       foo4_58;
    typedef decay<T58 volatile>::type    foo5_58;
    typedef decay<T58 [3]>::type         foo6_58;
    struct T59 { };
    typedef decay<T59>::type             foo1_59;
    typedef decay<T59&>::type            foo2_59;
    typedef decay<T59&&>::type           foo3_59;
    typedef decay<T59 const>::type       foo4_59;
    typedef decay<T59 volatile>::type    foo5_59;
    typedef decay<T59 [3]>::type         foo6_59;
    struct T60 { };
    typedef decay<T60>::type             foo1_60;
    typedef decay<T60&>::type            foo2_60;
    typedef decay<T60&&>::type           foo3_60;
    typedef decay<T60 const>::type       foo4_60;
    typedef decay<T60 volatile>::type    foo5_60;
    typedef decay<T60 [3]>::type         foo6_60;
    struct T61 { };
    typedef decay<T61>::type             foo1_61;
    typedef decay<T61&>::type            foo2_61;
    typedef decay<T61&&>::type           foo3_61;
    typedef decay<T61 const>::type       foo4_61;
    typedef decay<T61 volatile>::type    foo5_61;
    typedef decay<T61 [3]>::type         foo6_61;
    struct T62 { };
    typedef decay<T62>::type             foo1_62;
    typedef decay<T62&>::type            foo2_62;
    typedef decay<T62&&>::type           foo3_62;
    typedef decay<T62 const>::type       foo4_62;
    typedef decay<T62 volatile>::type    foo5_62;
    typedef decay<T62 [3]>::type         foo6_62;
    struct T63 { };
    typedef decay<T63>::type             foo1_63;
    typedef decay<T63&>::type            foo2_63;
    typedef decay<T63&&>::type           foo3_63;
    typedef decay<T63 const>::type       foo4_63;
    typedef decay<T63 volatile>::type    foo5_63;
    typedef decay<T63 [3]>::type         foo6_63;
    struct T64 { };
    typedef decay<T64>::type             foo1_64;
    typedef decay<T64&>::type            foo2_64;
    typedef decay<T64&&>::type           foo3_64;
    typedef decay<T64 const>::type       foo4_64;
    typedef decay<T64 volatile>::type    foo5_64;
    typedef decay<T64 [3]>::type         foo6_64;
    struct T65 { };
    typedef decay<T65>::type             foo1_65;
    typedef decay<T65&>::type            foo2_65;
    typedef decay<T65&&>::type           foo3_65;
    typedef decay<T65 const>::type       foo4_65;
    typedef decay<T65 volatile>::type    foo5_65;
    typedef decay<T65 [3]>::type         foo6_65;
    struct T66 { };
    typedef decay<T66>::type             foo1_66;
    typedef decay<T66&>::type            foo2_66;
    typedef decay<T66&&>::type           foo3_66;
    typedef decay<T66 const>::type       foo4_66;
    typedef decay<T66 volatile>::type    foo5_66;
    typedef decay<T66 [3]>::type         foo6_66;
    struct T67 { };
    typedef decay<T67>::type             foo1_67;
    typedef decay<T67&>::type            foo2_67;
    typedef decay<T67&&>::type           foo3_67;
    typedef decay<T67 const>::type       foo4_67;
    typedef decay<T67 volatile>::type    foo5_67;
    typedef decay<T67 [3]>::type         foo6_67;
    struct T68 { };
    typedef decay<T68>::type             foo1_68;
    typedef decay<T68&>::type            foo2_68;
    typedef decay<T68&&>::type           foo3_68;
    typedef decay<T68 const>::type       foo4_68;
    typedef decay<T68 volatile>::type    foo5_68;
    typedef decay<T68 [3]>::type         foo6_68;
    struct T69 { };
    typedef decay<T69>::type             foo1_69;
    typedef decay<T69&>::type            foo2_69;
    typedef decay<T69&&>::type           foo3_69;
    typedef decay<T69 const>::type       foo4_69;
    typedef decay<T69 volatile>::type    foo5_69;
    typedef decay<T69 [3]>::type         foo6_69;
    struct T70 { };
    typedef decay<T70>::type             foo1_70;
    typedef decay<T70&>::type            foo2_70;
    typedef decay<T70&&>::type           foo3_70;
    typedef decay<T70 const>::type       foo4_70;
    typedef decay<T70 volatile>::type    foo5_70;
    typedef decay<T70 [3]>::type         foo6_70;
    struct T71 { };
    typedef decay<T71>::type             foo1_71;
    typedef decay<T71&>::type            foo2_71;
    typedef decay<T71&&>::type           foo3_71;
    typedef decay<T71 const>::type       foo4_71;
    typedef decay<T71 volatile>::type    foo5_71;
    typedef decay<T71 [3]>::type         foo6_71;
    struct T72 { };
    typedef decay<T72>::type             foo1_72;
    typedef decay<T72&>::type            foo2_72;
    typedef decay<T72&&>::type           foo3_72;
    typedef decay<T72 const>::type       foo4_72;
    typedef decay<T72 volatile>::type    foo5_72;
    typedef decay<T72 [3]>::type         foo6_72;
    struct T73 { };
    typedef decay<T73>::type             foo1_73;
    typedef decay<T73&>::type            foo2_73;
    typedef decay<T73&&>::type           foo3_73;
    typedef decay<T73 const>::type       foo4_73;
    typedef decay<T73 volatile>::type    foo5_73;
    typedef decay<T73 [3]>::type         foo6_73;
    struct T74 { };
    typedef decay<T74>::type             foo1_74;
    typedef decay<T74&>::type            foo2_74;
    typedef decay<T74&&>::type           foo3_74;
    typedef decay<T74 const>::type       foo4_74;
    typedef decay<T74 volatile>::type    foo5_74;
    typedef decay<T74 [3]>::type         foo6_74;
    struct T75 { };
    typedef decay<T75>::type             foo1_75;
    typedef decay<T75&>::type            foo2_75;
    typedef decay<T75&&>::type           foo3_75;
    typedef decay<T75 const>::type       foo4_75;
    typedef decay<T75 volatile>::type    foo5_75;
    typedef decay<T75 [3]>::type         foo6_75;
    struct T76 { };
    typedef decay<T76>::type             foo1_76;
    typedef decay<T76&>::type            foo2_76;
    typedef decay<T76&&>::type           foo3_76;
    typedef decay<T76 const>::type       foo4_76;
    typedef decay<T76 volatile>::type    foo5_76;
    typedef decay<T76 [3]>::type         foo6_76;
    struct T77 { };
    typedef decay<T77>::type             foo1_77;
    typedef decay<T77&>::type            foo2_77;
    typedef decay<T77&&>::type           foo3_77;
    typedef decay<T77 const>::type       foo4_77;
    typedef decay<T77 volatile>::type    foo5_77;
    typedef decay<T77 [3]>::type         foo6_77;
    struct T78 { };
    typedef decay<T78>::type             foo1_78;
    typedef decay<T78&>::type            foo2_78;
    typedef decay<T78&&>::type           foo3_78;
    typedef decay<T78 const>::type       foo4_78;
    typedef decay<T78 volatile>::type    foo5_78;
    typedef decay<T78 [3]>::type         foo6_78;
    struct T79 { };
    typedef decay<T79>::type             foo1_79;
    typedef decay<T79&>::type            foo2_79;
    typedef decay<T79&&>::type           foo3_79;
    typedef decay<T79 const>::type       foo4_79;
    typedef decay<T79 volatile>::type    foo5_79;
    typedef decay<T79 [3]>::type         foo6_79;
    struct T80 { };
    typedef decay<T80>::type             foo1_80;
    typedef decay<T80&>::type            foo2_80;
    typedef decay<T80&&>::type           foo3_80;
    typedef decay<T80 const>::type       foo4_80;
    typedef decay<T80 volatile>::type    foo5_80;
    typedef decay<T80 [3]>::type         foo6_80;
    struct T81 { };
    typedef decay<T81>::type             foo1_81;
    typedef decay<T81&>::type            foo2_81;
    typedef decay<T81&&>::type           foo3_81;
    typedef decay<T81 const>::type       foo4_81;
    typedef decay<T81 volatile>::type    foo5_81;
    typedef decay<T81 [3]>::type         foo6_81;
    struct T82 { };
    typedef decay<T82>::type             foo1_82;
    typedef decay<T82&>::type            foo2_82;
    typedef decay<T82&&>::type           foo3_82;
    typedef decay<T82 const>::type       foo4_82;
    typedef decay<T82 volatile>::type    foo5_82;
    typedef decay<T82 [3]>::type         foo6_82;
    struct T83 { };
    typedef decay<T83>::type             foo1_83;
    typedef decay<T83&>::type            foo2_83;
    typedef decay<T83&&>::type           foo3_83;
    typedef decay<T83 const>::type       foo4_83;
    typedef decay<T83 volatile>::type    foo5_83;
    typedef decay<T83 [3]>::type         foo6_83;
    struct T84 { };
    typedef decay<T84>::type             foo1_84;
    typedef decay<T84&>::type            foo2_84;
    typedef decay<T84&&>::type           foo3_84;
    typedef decay<T84 const>::type       foo4_84;
    typedef decay<T84 volatile>::type    foo5_84;
    typedef decay<T84 [3]>::type         foo6_84;
    struct T85 { };
    typedef decay<T85>::type             foo1_85;
    typedef decay<T85&>::type            foo2_85;
    typedef decay<T85&&>::type           foo3_85;
    typedef decay<T85 const>::type       foo4_85;
    typedef decay<T85 volatile>::type    foo5_85;
    typedef decay<T85 [3]>::type         foo6_85;
    struct T86 { };
    typedef decay<T86>::type             foo1_86;
    typedef decay<T86&>::type            foo2_86;
    typedef decay<T86&&>::type           foo3_86;
    typedef decay<T86 const>::type       foo4_86;
    typedef decay<T86 volatile>::type    foo5_86;
    typedef decay<T86 [3]>::type         foo6_86;
    struct T87 { };
    typedef decay<T87>::type             foo1_87;
    typedef decay<T87&>::type            foo2_87;
    typedef decay<T87&&>::type           foo3_87;
    typedef decay<T87 const>::type       foo4_87;
    typedef decay<T87 volatile>::type    foo5_87;
    typedef decay<T87 [3]>::type         foo6_87;
    struct T88 { };
    typedef decay<T88>::type             foo1_88;
    typedef decay<T88&>::type            foo2_88;
    typedef decay<T88&&>::type           foo3_88;
    typedef decay<T88 const>::type       foo4_88;
    typedef decay<T88 volatile>::type    foo5_88;
    typedef decay<T88 [3]>::type         foo6_88;
    struct T89 { };
    typedef decay<T89>::type             foo1_89;
    typedef decay<T89&>::type            foo2_89;
    typedef decay<T89&&>::type           foo3_89;
    typedef decay<T89 const>::type       foo4_89;
    typedef decay<T89 volatile>::type    foo5_89;
    typedef decay<T89 [3]>::type         foo6_89;
    struct T90 { };
    typedef decay<T90>::type             foo1_90;
    typedef decay<T90&>::type            foo2_90;
    typedef decay<T90&&>::type           foo3_90;
    typedef decay<T90 const>::type       foo4_90;
    typedef decay<T90 volatile>::type    foo5_90;
    typedef decay<T90 [3]>::type         foo6_90;
    struct T91 { };
    typedef decay<T91>::type             foo1_91;
    typedef decay<T91&>::type            foo2_91;
    typedef decay<T91&&>::type           foo3_91;
    typedef decay<T91 const>::type       foo4_91;
    typedef decay<T91 volatile>::type    foo5_91;
    typedef decay<T91 [3]>::type         foo6_91;
    struct T92 { };
    typedef decay<T92>::type             foo1_92;
    typedef decay<T92&>::type            foo2_92;
    typedef decay<T92&&>::type           foo3_92;
    typedef decay<T92 const>::type       foo4_92;
    typedef decay<T92 volatile>::type    foo5_92;
    typedef decay<T92 [3]>::type         foo6_92;
    struct T93 { };
    typedef decay<T93>::type             foo1_93;
    typedef decay<T93&>::type            foo2_93;
    typedef decay<T93&&>::type           foo3_93;
    typedef decay<T93 const>::type       foo4_93;
    typedef decay<T93 volatile>::type    foo5_93;
    typedef decay<T93 [3]>::type         foo6_93;
    struct T94 { };
    typedef decay<T94>::type             foo1_94;
    typedef decay<T94&>::type            foo2_94;
    typedef decay<T94&&>::type           foo3_94;
    typedef decay<T94 const>::type       foo4_94;
    typedef decay<T94 volatile>::type    foo5_94;
    typedef decay<T94 [3]>::type         foo6_94;
    struct T95 { };
    typedef decay<T95>::type             foo1_95;
    typedef decay<T95&>::type            foo2_95;
    typedef decay<T95&&>::type           foo3_95;
    typedef decay<T95 const>::type       foo4_95;
    typedef decay<T95 volatile>::type    foo5_95;
    typedef decay<T95 [3]>::type         foo6_95;
    struct T96 { };
    typedef decay<T96>::type             foo1_96;
    typedef decay<T96&>::type            foo2_96;
    typedef decay<T96&&>::type           foo3_96;
    typedef decay<T96 const>::type       foo4_96;
    typedef decay<T96 volatile>::type    foo5_96;
    typedef decay<T96 [3]>::type         foo6_96;
    struct T97 { };
    typedef decay<T97>::type             foo1_97;
    typedef decay<T97&>::type            foo2_97;
    typedef decay<T97&&>::type           foo3_97;
    typedef decay<T97 const>::type       foo4_97;
    typedef decay<T97 volatile>::type    foo5_97;
    typedef decay<T97 [3]>::type         foo6_97;
    struct T98 { };
    typedef decay<T98>::type             foo1_98;
    typedef decay<T98&>::type            foo2_98;
    typedef decay<T98&&>::type           foo3_98;
    typedef decay<T98 const>::type       foo4_98;
    typedef decay<T98 volatile>::type    foo5_98;
    typedef decay<T98 [3]>::type         foo6_98;
    struct T99 { };
    typedef decay<T99>::type             foo1_99;
    typedef decay<T99&>::type            foo2_99;
    typedef decay<T99&&>::type           foo3_99;
    typedef decay<T99 const>::type       foo4_99;
    typedef decay<T99 volatile>::type    foo5_99;
    typedef decay<T99 [3]>::type         foo6_99;
    struct T100 { };
    typedef decay<T100>::type             foo1_100;
    typedef decay<T100&>::type            foo2_100;
    typedef decay<T100&&>::type           foo3_100;
    typedef decay<T100 const>::type       foo4_100;
    typedef decay<T100 volatile>::type    foo5_100;
    typedef decay<T100 [3]>::type         foo6_100;
    struct T101 { };
    typedef decay<T101>::type             foo1_101;
    typedef decay<T101&>::type            foo2_101;
    typedef decay<T101&&>::type           foo3_101;
    typedef decay<T101 const>::type       foo4_101;
    typedef decay<T101 volatile>::type    foo5_101;
    typedef decay<T101 [3]>::type         foo6_101;
    struct T102 { };
    typedef decay<T102>::type             foo1_102;
    typedef decay<T102&>::type            foo2_102;
    typedef decay<T102&&>::type           foo3_102;
    typedef decay<T102 const>::type       foo4_102;
    typedef decay<T102 volatile>::type    foo5_102;
    typedef decay<T102 [3]>::type         foo6_102;
    struct T103 { };
    typedef decay<T103>::type             foo1_103;
    typedef decay<T103&>::type            foo2_103;
    typedef decay<T103&&>::type           foo3_103;
    typedef decay<T103 const>::type       foo4_103;
    typedef decay<T103 volatile>::type    foo5_103;
    typedef decay<T103 [3]>::type         foo6_103;
    struct T104 { };
    typedef decay<T104>::type             foo1_104;
    typedef decay<T104&>::type            foo2_104;
    typedef decay<T104&&>::type           foo3_104;
    typedef decay<T104 const>::type       foo4_104;
    typedef decay<T104 volatile>::type    foo5_104;
    typedef decay<T104 [3]>::type         foo6_104;
    struct T105 { };
    typedef decay<T105>::type             foo1_105;
    typedef decay<T105&>::type            foo2_105;
    typedef decay<T105&&>::type           foo3_105;
    typedef decay<T105 const>::type       foo4_105;
    typedef decay<T105 volatile>::type    foo5_105;
    typedef decay<T105 [3]>::type         foo6_105;
    struct T106 { };
    typedef decay<T106>::type             foo1_106;
    typedef decay<T106&>::type            foo2_106;
    typedef decay<T106&&>::type           foo3_106;
    typedef decay<T106 const>::type       foo4_106;
    typedef decay<T106 volatile>::type    foo5_106;
    typedef decay<T106 [3]>::type         foo6_106;
    struct T107 { };
    typedef decay<T107>::type             foo1_107;
    typedef decay<T107&>::type            foo2_107;
    typedef decay<T107&&>::type           foo3_107;
    typedef decay<T107 const>::type       foo4_107;
    typedef decay<T107 volatile>::type    foo5_107;
    typedef decay<T107 [3]>::type         foo6_107;
    struct T108 { };
    typedef decay<T108>::type             foo1_108;
    typedef decay<T108&>::type            foo2_108;
    typedef decay<T108&&>::type           foo3_108;
    typedef decay<T108 const>::type       foo4_108;
    typedef decay<T108 volatile>::type    foo5_108;
    typedef decay<T108 [3]>::type         foo6_108;
    struct T109 { };
    typedef decay<T109>::type             foo1_109;
    typedef decay<T109&>::type            foo2_109;
    typedef decay<T109&&>::type           foo3_109;
    typedef decay<T109 const>::type       foo4_109;
    typedef decay<T109 volatile>::type    foo5_109;
    typedef decay<T109 [3]>::type         foo6_109;
    struct T110 { };
    typedef decay<T110>::type             foo1_110;
    typedef decay<T110&>::type            foo2_110;
    typedef decay<T110&&>::type           foo3_110;
    typedef decay<T110 const>::type       foo4_110;
    typedef decay<T110 volatile>::type    foo5_110;
    typedef decay<T110 [3]>::type         foo6_110;
    struct T111 { };
    typedef decay<T111>::type             foo1_111;
    typedef decay<T111&>::type            foo2_111;
    typedef decay<T111&&>::type           foo3_111;
    typedef decay<T111 const>::type       foo4_111;
    typedef decay<T111 volatile>::type    foo5_111;
    typedef decay<T111 [3]>::type         foo6_111;
    struct T112 { };
    typedef decay<T112>::type             foo1_112;
    typedef decay<T112&>::type            foo2_112;
    typedef decay<T112&&>::type           foo3_112;
    typedef decay<T112 const>::type       foo4_112;
    typedef decay<T112 volatile>::type    foo5_112;
    typedef decay<T112 [3]>::type         foo6_112;
    struct T113 { };
    typedef decay<T113>::type             foo1_113;
    typedef decay<T113&>::type            foo2_113;
    typedef decay<T113&&>::type           foo3_113;
    typedef decay<T113 const>::type       foo4_113;
    typedef decay<T113 volatile>::type    foo5_113;
    typedef decay<T113 [3]>::type         foo6_113;
    struct T114 { };
    typedef decay<T114>::type             foo1_114;
    typedef decay<T114&>::type            foo2_114;
    typedef decay<T114&&>::type           foo3_114;
    typedef decay<T114 const>::type       foo4_114;
    typedef decay<T114 volatile>::type    foo5_114;
    typedef decay<T114 [3]>::type         foo6_114;
    struct T115 { };
    typedef decay<T115>::type             foo1_115;
    typedef decay<T115&>::type            foo2_115;
    typedef decay<T115&&>::type           foo3_115;
    typedef decay<T115 const>::type       foo4_115;
    typedef decay<T115 volatile>::type    foo5_115;
    typedef decay<T115 [3]>::type         foo6_115;
    struct T116 { };
    typedef decay<T116>::type             foo1_116;
    typedef decay<T116&>::type            foo2_116;
    typedef decay<T116&&>::type           foo3_116;
    typedef decay<T116 const>::type       foo4_116;
    typedef decay<T116 volatile>::type    foo5_116;
    typedef decay<T116 [3]>::type         foo6_116;
    struct T117 { };
    typedef decay<T117>::type             foo1_117;
    typedef decay<T117&>::type            foo2_117;
    typedef decay<T117&&>::type           foo3_117;
    typedef decay<T117 const>::type       foo4_117;
    typedef decay<T117 volatile>::type    foo5_117;
    typedef decay<T117 [3]>::type         foo6_117;
    struct T118 { };
    typedef decay<T118>::type             foo1_118;
    typedef decay<T118&>::type            foo2_118;
    typedef decay<T118&&>::type           foo3_118;
    typedef decay<T118 const>::type       foo4_118;
    typedef decay<T118 volatile>::type    foo5_118;
    typedef decay<T118 [3]>::type         foo6_118;
    struct T119 { };
    typedef decay<T119>::type             foo1_119;
    typedef decay<T119&>::type            foo2_119;
    typedef decay<T119&&>::type           foo3_119;
    typedef decay<T119 const>::type       foo4_119;
    typedef decay<T119 volatile>::type    foo5_119;
    typedef decay<T119 [3]>::type         foo6_119;
    struct T120 { };
    typedef decay<T120>::type             foo1_120;
    typedef decay<T120&>::type            foo2_120;
    typedef decay<T120&&>::type           foo3_120;
    typedef decay<T120 const>::type       foo4_120;
    typedef decay<T120 volatile>::type    foo5_120;
    typedef decay<T120 [3]>::type         foo6_120;
    struct T121 { };
    typedef decay<T121>::type             foo1_121;
    typedef decay<T121&>::type            foo2_121;
    typedef decay<T121&&>::type           foo3_121;
    typedef decay<T121 const>::type       foo4_121;
    typedef decay<T121 volatile>::type    foo5_121;
    typedef decay<T121 [3]>::type         foo6_121;
    struct T122 { };
    typedef decay<T122>::type             foo1_122;
    typedef decay<T122&>::type            foo2_122;
    typedef decay<T122&&>::type           foo3_122;
    typedef decay<T122 const>::type       foo4_122;
    typedef decay<T122 volatile>::type    foo5_122;
    typedef decay<T122 [3]>::type         foo6_122;
    struct T123 { };
    typedef decay<T123>::type             foo1_123;
    typedef decay<T123&>::type            foo2_123;
    typedef decay<T123&&>::type           foo3_123;
    typedef decay<T123 const>::type       foo4_123;
    typedef decay<T123 volatile>::type    foo5_123;
    typedef decay<T123 [3]>::type         foo6_123;
    struct T124 { };
    typedef decay<T124>::type             foo1_124;
    typedef decay<T124&>::type            foo2_124;
    typedef decay<T124&&>::type           foo3_124;
    typedef decay<T124 const>::type       foo4_124;
    typedef decay<T124 volatile>::type    foo5_124;
    typedef decay<T124 [3]>::type         foo6_124;
    struct T125 { };
    typedef decay<T125>::type             foo1_125;
    typedef decay<T125&>::type            foo2_125;
    typedef decay<T125&&>::type           foo3_125;
    typedef decay<T125 const>::type       foo4_125;
    typedef decay<T125 volatile>::type    foo5_125;
    typedef decay<T125 [3]>::type         foo6_125;
    struct T126 { };
    typedef decay<T126>::type             foo1_126;
    typedef decay<T126&>::type            foo2_126;
    typedef decay<T126&&>::type           foo3_126;
    typedef decay<T126 const>::type       foo4_126;
    typedef decay<T126 volatile>::type    foo5_126;
    typedef decay<T126 [3]>::type         foo6_126;
    struct T127 { };
    typedef decay<T127>::type             foo1_127;
    typedef decay<T127&>::type            foo2_127;
    typedef decay<T127&&>::type           foo3_127;
    typedef decay<T127 const>::type       foo4_127;
    typedef decay<T127 volatile>::type    foo5_127;
    typedef decay<T127 [3]>::type         foo6_127;
    struct T128 { };
    typedef decay<T128>::type             foo1_128;
    typedef decay<T128&>::type            foo2_128;
    typedef decay<T128&&>::type           foo3_128;
    typedef decay<T128 const>::type       foo4_128;
    typedef decay<T128 volatile>::type    foo5_128;
    typedef decay<T128 [3]>::type         foo6_128;
    struct T129 { };
    typedef decay<T129>::type             foo1_129;
    typedef decay<T129&>::type            foo2_129;
    typedef decay<T129&&>::type           foo3_129;
    typedef decay<T129 const>::type       foo4_129;
    typedef decay<T129 volatile>::type    foo5_129;
    typedef decay<T129 [3]>::type         foo6_129;
    struct T130 { };
    typedef decay<T130>::type             foo1_130;
    typedef decay<T130&>::type            foo2_130;
    typedef decay<T130&&>::type           foo3_130;
    typedef decay<T130 const>::type       foo4_130;
    typedef decay<T130 volatile>::type    foo5_130;
    typedef decay<T130 [3]>::type         foo6_130;
    struct T131 { };
    typedef decay<T131>::type             foo1_131;
    typedef decay<T131&>::type            foo2_131;
    typedef decay<T131&&>::type           foo3_131;
    typedef decay<T131 const>::type       foo4_131;
    typedef decay<T131 volatile>::type    foo5_131;
    typedef decay<T131 [3]>::type         foo6_131;
    struct T132 { };
    typedef decay<T132>::type             foo1_132;
    typedef decay<T132&>::type            foo2_132;
    typedef decay<T132&&>::type           foo3_132;
    typedef decay<T132 const>::type       foo4_132;
    typedef decay<T132 volatile>::type    foo5_132;
    typedef decay<T132 [3]>::type         foo6_132;
    struct T133 { };
    typedef decay<T133>::type             foo1_133;
    typedef decay<T133&>::type            foo2_133;
    typedef decay<T133&&>::type           foo3_133;
    typedef decay<T133 const>::type       foo4_133;
    typedef decay<T133 volatile>::type    foo5_133;
    typedef decay<T133 [3]>::type         foo6_133;
    struct T134 { };
    typedef decay<T134>::type             foo1_134;
    typedef decay<T134&>::type            foo2_134;
    typedef decay<T134&&>::type           foo3_134;
    typedef decay<T134 const>::type       foo4_134;
    typedef decay<T134 volatile>::type    foo5_134;
    typedef decay<T134 [3]>::type         foo6_134;
    struct T135 { };
    typedef decay<T135>::type             foo1_135;
    typedef decay<T135&>::type            foo2_135;
    typedef decay<T135&&>::type           foo3_135;
    typedef decay<T135 const>::type       foo4_135;
    typedef decay<T135 volatile>::type    foo5_135;
    typedef decay<T135 [3]>::type         foo6_135;
    struct T136 { };
    typedef decay<T136>::type             foo1_136;
    typedef decay<T136&>::type            foo2_136;
    typedef decay<T136&&>::type           foo3_136;
    typedef decay<T136 const>::type       foo4_136;
    typedef decay<T136 volatile>::type    foo5_136;
    typedef decay<T136 [3]>::type         foo6_136;
    struct T137 { };
    typedef decay<T137>::type             foo1_137;
    typedef decay<T137&>::type            foo2_137;
    typedef decay<T137&&>::type           foo3_137;
    typedef decay<T137 const>::type       foo4_137;
    typedef decay<T137 volatile>::type    foo5_137;
    typedef decay<T137 [3]>::type         foo6_137;
    struct T138 { };
    typedef decay<T138>::type             foo1_138;
    typedef decay<T138&>::type            foo2_138;
    typedef decay<T138&&>::type           foo3_138;
    typedef decay<T138 const>::type       foo4_138;
    typedef decay<T138 volatile>::type    foo5_138;
    typedef decay<T138 [3]>::type         foo6_138;
    struct T139 { };
    typedef decay<T139>::type             foo1_139;
    typedef decay<T139&>::type            foo2_139;
    typedef decay<T139&&>::type           foo3_139;
    typedef decay<T139 const>::type       foo4_139;
    typedef decay<T139 volatile>::type    foo5_139;
    typedef decay<T139 [3]>::type         foo6_139;
    struct T140 { };
    typedef decay<T140>::type             foo1_140;
    typedef decay<T140&>::type            foo2_140;
    typedef decay<T140&&>::type           foo3_140;
    typedef decay<T140 const>::type       foo4_140;
    typedef decay<T140 volatile>::type    foo5_140;
    typedef decay<T140 [3]>::type         foo6_140;
    struct T141 { };
    typedef decay<T141>::type             foo1_141;
    typedef decay<T141&>::type            foo2_141;
    typedef decay<T141&&>::type           foo3_141;
    typedef decay<T141 const>::type       foo4_141;
    typedef decay<T141 volatile>::type    foo5_141;
    typedef decay<T141 [3]>::type         foo6_141;
    struct T142 { };
    typedef decay<T142>::type             foo1_142;
    typedef decay<T142&>::type            foo2_142;
    typedef decay<T142&&>::type           foo3_142;
    typedef decay<T142 const>::type       foo4_142;
    typedef decay<T142 volatile>::type    foo5_142;
    typedef decay<T142 [3]>::type         foo6_142;
    struct T143 { };
    typedef decay<T143>::type             foo1_143;
    typedef decay<T143&>::type            foo2_143;
    typedef decay<T143&&>::type           foo3_143;
    typedef decay<T143 const>::type       foo4_143;
    typedef decay<T143 volatile>::type    foo5_143;
    typedef decay<T143 [3]>::type         foo6_143;
    struct T144 { };
    typedef decay<T144>::type             foo1_144;
    typedef decay<T144&>::type            foo2_144;
    typedef decay<T144&&>::type           foo3_144;
    typedef decay<T144 const>::type       foo4_144;
    typedef decay<T144 volatile>::type    foo5_144;
    typedef decay<T144 [3]>::type         foo6_144;
    struct T145 { };
    typedef decay<T145>::type             foo1_145;
    typedef decay<T145&>::type            foo2_145;
    typedef decay<T145&&>::type           foo3_145;
    typedef decay<T145 const>::type       foo4_145;
    typedef decay<T145 volatile>::type    foo5_145;
    typedef decay<T145 [3]>::type         foo6_145;
    struct T146 { };
    typedef decay<T146>::type             foo1_146;
    typedef decay<T146&>::type            foo2_146;
    typedef decay<T146&&>::type           foo3_146;
    typedef decay<T146 const>::type       foo4_146;
    typedef decay<T146 volatile>::type    foo5_146;
    typedef decay<T146 [3]>::type         foo6_146;
    struct T147 { };
    typedef decay<T147>::type             foo1_147;
    typedef decay<T147&>::type            foo2_147;
    typedef decay<T147&&>::type           foo3_147;
    typedef decay<T147 const>::type       foo4_147;
    typedef decay<T147 volatile>::type    foo5_147;
    typedef decay<T147 [3]>::type         foo6_147;
    struct T148 { };
    typedef decay<T148>::type             foo1_148;
    typedef decay<T148&>::type            foo2_148;
    typedef decay<T148&&>::type           foo3_148;
    typedef decay<T148 const>::type       foo4_148;
    typedef decay<T148 volatile>::type    foo5_148;
    typedef decay<T148 [3]>::type         foo6_148;
    struct T149 { };
    typedef decay<T149>::type             foo1_149;
    typedef decay<T149&>::type            foo2_149;
    typedef decay<T149&&>::type           foo3_149;
    typedef decay<T149 const>::type       foo4_149;
    typedef decay<T149 volatile>::type    foo5_149;
    typedef decay<T149 [3]>::type         foo6_149;
    struct T150 { };
    typedef decay<T150>::type             foo1_150;
    typedef decay<T150&>::type            foo2_150;
    typedef decay<T150&&>::type           foo3_150;
    typedef decay<T150 const>::type       foo4_150;
    typedef decay<T150 volatile>::type    foo5_150;
    typedef decay<T150 [3]>::type         foo6_150;
    struct T151 { };
    typedef decay<T151>::type             foo1_151;
    typedef decay<T151&>::type            foo2_151;
    typedef decay<T151&&>::type           foo3_151;
    typedef decay<T151 const>::type       foo4_151;
    typedef decay<T151 volatile>::type    foo5_151;
    typedef decay<T151 [3]>::type         foo6_151;
    struct T152 { };
    typedef decay<T152>::type             foo1_152;
    typedef decay<T152&>::type            foo2_152;
    typedef decay<T152&&>::type           foo3_152;
    typedef decay<T152 const>::type       foo4_152;
    typedef decay<T152 volatile>::type    foo5_152;
    typedef decay<T152 [3]>::type         foo6_152;
    struct T153 { };
    typedef decay<T153>::type             foo1_153;
    typedef decay<T153&>::type            foo2_153;
    typedef decay<T153&&>::type           foo3_153;
    typedef decay<T153 const>::type       foo4_153;
    typedef decay<T153 volatile>::type    foo5_153;
    typedef decay<T153 [3]>::type         foo6_153;
    struct T154 { };
    typedef decay<T154>::type             foo1_154;
    typedef decay<T154&>::type            foo2_154;
    typedef decay<T154&&>::type           foo3_154;
    typedef decay<T154 const>::type       foo4_154;
    typedef decay<T154 volatile>::type    foo5_154;
    typedef decay<T154 [3]>::type         foo6_154;
    struct T155 { };
    typedef decay<T155>::type             foo1_155;
    typedef decay<T155&>::type            foo2_155;
    typedef decay<T155&&>::type           foo3_155;
    typedef decay<T155 const>::type       foo4_155;
    typedef decay<T155 volatile>::type    foo5_155;
    typedef decay<T155 [3]>::type         foo6_155;
    struct T156 { };
    typedef decay<T156>::type             foo1_156;
    typedef decay<T156&>::type            foo2_156;
    typedef decay<T156&&>::type           foo3_156;
    typedef decay<T156 const>::type       foo4_156;
    typedef decay<T156 volatile>::type    foo5_156;
    typedef decay<T156 [3]>::type         foo6_156;
    struct T157 { };
    typedef decay<T157>::type             foo1_157;
    typedef decay<T157&>::type            foo2_157;
    typedef decay<T157&&>::type           foo3_157;
    typedef decay<T157 const>::type       foo4_157;
    typedef decay<T157 volatile>::type    foo5_157;
    typedef decay<T157 [3]>::type         foo6_157;
    struct T158 { };
    typedef decay<T158>::type             foo1_158;
    typedef decay<T158&>::type            foo2_158;
    typedef decay<T158&&>::type           foo3_158;
    typedef decay<T158 const>::type       foo4_158;
    typedef decay<T158 volatile>::type    foo5_158;
    typedef decay<T158 [3]>::type         foo6_158;
    struct T159 { };
    typedef decay<T159>::type             foo1_159;
    typedef decay<T159&>::type            foo2_159;
    typedef decay<T159&&>::type           foo3_159;
    typedef decay<T159 const>::type       foo4_159;
    typedef decay<T159 volatile>::type    foo5_159;
    typedef decay<T159 [3]>::type         foo6_159;
    struct T160 { };
    typedef decay<T160>::type             foo1_160;
    typedef decay<T160&>::type            foo2_160;
    typedef decay<T160&&>::type           foo3_160;
    typedef decay<T160 const>::type       foo4_160;
    typedef decay<T160 volatile>::type    foo5_160;
    typedef decay<T160 [3]>::type         foo6_160;
    struct T161 { };
    typedef decay<T161>::type             foo1_161;
    typedef decay<T161&>::type            foo2_161;
    typedef decay<T161&&>::type           foo3_161;
    typedef decay<T161 const>::type       foo4_161;
    typedef decay<T161 volatile>::type    foo5_161;
    typedef decay<T161 [3]>::type         foo6_161;
    struct T162 { };
    typedef decay<T162>::type             foo1_162;
    typedef decay<T162&>::type            foo2_162;
    typedef decay<T162&&>::type           foo3_162;
    typedef decay<T162 const>::type       foo4_162;
    typedef decay<T162 volatile>::type    foo5_162;
    typedef decay<T162 [3]>::type         foo6_162;
    struct T163 { };
    typedef decay<T163>::type             foo1_163;
    typedef decay<T163&>::type            foo2_163;
    typedef decay<T163&&>::type           foo3_163;
    typedef decay<T163 const>::type       foo4_163;
    typedef decay<T163 volatile>::type    foo5_163;
    typedef decay<T163 [3]>::type         foo6_163;
    struct T164 { };
    typedef decay<T164>::type             foo1_164;
    typedef decay<T164&>::type            foo2_164;
    typedef decay<T164&&>::type           foo3_164;
    typedef decay<T164 const>::type       foo4_164;
    typedef decay<T164 volatile>::type    foo5_164;
    typedef decay<T164 [3]>::type         foo6_164;
    struct T165 { };
    typedef decay<T165>::type             foo1_165;
    typedef decay<T165&>::type            foo2_165;
    typedef decay<T165&&>::type           foo3_165;
    typedef decay<T165 const>::type       foo4_165;
    typedef decay<T165 volatile>::type    foo5_165;
    typedef decay<T165 [3]>::type         foo6_165;
    struct T166 { };
    typedef decay<T166>::type             foo1_166;
    typedef decay<T166&>::type            foo2_166;
    typedef decay<T166&&>::type           foo3_166;
    typedef decay<T166 const>::type       foo4_166;
    typedef decay<T166 volatile>::type    foo5_166;
    typedef decay<T166 [3]>::type         foo6_166;
    struct T167 { };
    typedef decay<T167>::type             foo1_167;
    typedef decay<T167&>::type            foo2_167;
    typedef decay<T167&&>::type           foo3_167;
    typedef decay<T167 const>::type       foo4_167;
    typedef decay<T167 volatile>::type    foo5_167;
    typedef decay<T167 [3]>::type         foo6_167;
    struct T168 { };
    typedef decay<T168>::type             foo1_168;
    typedef decay<T168&>::type            foo2_168;
    typedef decay<T168&&>::type           foo3_168;
    typedef decay<T168 const>::type       foo4_168;
    typedef decay<T168 volatile>::type    foo5_168;
    typedef decay<T168 [3]>::type         foo6_168;
    struct T169 { };
    typedef decay<T169>::type             foo1_169;
    typedef decay<T169&>::type            foo2_169;
    typedef decay<T169&&>::type           foo3_169;
    typedef decay<T169 const>::type       foo4_169;
    typedef decay<T169 volatile>::type    foo5_169;
    typedef decay<T169 [3]>::type         foo6_169;
    struct T170 { };
    typedef decay<T170>::type             foo1_170;
    typedef decay<T170&>::type            foo2_170;
    typedef decay<T170&&>::type           foo3_170;
    typedef decay<T170 const>::type       foo4_170;
    typedef decay<T170 volatile>::type    foo5_170;
    typedef decay<T170 [3]>::type         foo6_170;
    struct T171 { };
    typedef decay<T171>::type             foo1_171;
    typedef decay<T171&>::type            foo2_171;
    typedef decay<T171&&>::type           foo3_171;
    typedef decay<T171 const>::type       foo4_171;
    typedef decay<T171 volatile>::type    foo5_171;
    typedef decay<T171 [3]>::type         foo6_171;
    struct T172 { };
    typedef decay<T172>::type             foo1_172;
    typedef decay<T172&>::type            foo2_172;
    typedef decay<T172&&>::type           foo3_172;
    typedef decay<T172 const>::type       foo4_172;
    typedef decay<T172 volatile>::type    foo5_172;
    typedef decay<T172 [3]>::type         foo6_172;
    struct T173 { };
    typedef decay<T173>::type             foo1_173;
    typedef decay<T173&>::type            foo2_173;
    typedef decay<T173&&>::type           foo3_173;
    typedef decay<T173 const>::type       foo4_173;
    typedef decay<T173 volatile>::type    foo5_173;
    typedef decay<T173 [3]>::type         foo6_173;
    struct T174 { };
    typedef decay<T174>::type             foo1_174;
    typedef decay<T174&>::type            foo2_174;
    typedef decay<T174&&>::type           foo3_174;
    typedef decay<T174 const>::type       foo4_174;
    typedef decay<T174 volatile>::type    foo5_174;
    typedef decay<T174 [3]>::type         foo6_174;
    struct T175 { };
    typedef decay<T175>::type             foo1_175;
    typedef decay<T175&>::type            foo2_175;
    typedef decay<T175&&>::type           foo3_175;
    typedef decay<T175 const>::type       foo4_175;
    typedef decay<T175 volatile>::type    foo5_175;
    typedef decay<T175 [3]>::type         foo6_175;
    struct T176 { };
    typedef decay<T176>::type             foo1_176;
    typedef decay<T176&>::type            foo2_176;
    typedef decay<T176&&>::type           foo3_176;
    typedef decay<T176 const>::type       foo4_176;
    typedef decay<T176 volatile>::type    foo5_176;
    typedef decay<T176 [3]>::type         foo6_176;
    struct T177 { };
    typedef decay<T177>::type             foo1_177;
    typedef decay<T177&>::type            foo2_177;
    typedef decay<T177&&>::type           foo3_177;
    typedef decay<T177 const>::type       foo4_177;
    typedef decay<T177 volatile>::type    foo5_177;
    typedef decay<T177 [3]>::type         foo6_177;
    struct T178 { };
    typedef decay<T178>::type             foo1_178;
    typedef decay<T178&>::type            foo2_178;
    typedef decay<T178&&>::type           foo3_178;
    typedef decay<T178 const>::type       foo4_178;
    typedef decay<T178 volatile>::type    foo5_178;
    typedef decay<T178 [3]>::type         foo6_178;
    struct T179 { };
    typedef decay<T179>::type             foo1_179;
    typedef decay<T179&>::type            foo2_179;
    typedef decay<T179&&>::type           foo3_179;
    typedef decay<T179 const>::type       foo4_179;
    typedef decay<T179 volatile>::type    foo5_179;
    typedef decay<T179 [3]>::type         foo6_179;
    struct T180 { };
    typedef decay<T180>::type             foo1_180;
    typedef decay<T180&>::type            foo2_180;
    typedef decay<T180&&>::type           foo3_180;
    typedef decay<T180 const>::type       foo4_180;
    typedef decay<T180 volatile>::type    foo5_180;
    typedef decay<T180 [3]>::type         foo6_180;
    struct T181 { };
    typedef decay<T181>::type             foo1_181;
    typedef decay<T181&>::type            foo2_181;
    typedef decay<T181&&>::type           foo3_181;
    typedef decay<T181 const>::type       foo4_181;
    typedef decay<T181 volatile>::type    foo5_181;
    typedef decay<T181 [3]>::type         foo6_181;
    struct T182 { };
    typedef decay<T182>::type             foo1_182;
    typedef decay<T182&>::type            foo2_182;
    typedef decay<T182&&>::type           foo3_182;
    typedef decay<T182 const>::type       foo4_182;
    typedef decay<T182 volatile>::type    foo5_182;
    typedef decay<T182 [3]>::type         foo6_182;
    struct T183 { };
    typedef decay<T183>::type             foo1_183;
    typedef decay<T183&>::type            foo2_183;
    typedef decay<T183&&>::type           foo3_183;
    typedef decay<T183 const>::type       foo4_183;
    typedef decay<T183 volatile>::type    foo5_183;
    typedef decay<T183 [3]>::type         foo6_183;
    struct T184 { };
    typedef decay<T184>::type             foo1_184;
    typedef decay<T184&>::type            foo2_184;
    typedef decay<T184&&>::type           foo3_184;
    typedef decay<T184 const>::type       foo4_184;
    typedef decay<T184 volatile>::type    foo5_184;
    typedef decay<T184 [3]>::type         foo6_184;
    struct T185 { };
    typedef decay<T185>::type             foo1_185;
    typedef decay<T185&>::type            foo2_185;
    typedef decay<T185&&>::type           foo3_185;
    typedef decay<T185 const>::type       foo4_185;
    typedef decay<T185 volatile>::type    foo5_185;
    typedef decay<T185 [3]>::type         foo6_185;
    struct T186 { };
    typedef decay<T186>::type             foo1_186;
    typedef decay<T186&>::type            foo2_186;
    typedef decay<T186&&>::type           foo3_186;
    typedef decay<T186 const>::type       foo4_186;
    typedef decay<T186 volatile>::type    foo5_186;
    typedef decay<T186 [3]>::type         foo6_186;
    struct T187 { };
    typedef decay<T187>::type             foo1_187;
    typedef decay<T187&>::type            foo2_187;
    typedef decay<T187&&>::type           foo3_187;
    typedef decay<T187 const>::type       foo4_187;
    typedef decay<T187 volatile>::type    foo5_187;
    typedef decay<T187 [3]>::type         foo6_187;
    struct T188 { };
    typedef decay<T188>::type             foo1_188;
    typedef decay<T188&>::type            foo2_188;
    typedef decay<T188&&>::type           foo3_188;
    typedef decay<T188 const>::type       foo4_188;
    typedef decay<T188 volatile>::type    foo5_188;
    typedef decay<T188 [3]>::type         foo6_188;
    struct T189 { };
    typedef decay<T189>::type             foo1_189;
    typedef decay<T189&>::type            foo2_189;
    typedef decay<T189&&>::type           foo3_189;
    typedef decay<T189 const>::type       foo4_189;
    typedef decay<T189 volatile>::type    foo5_189;
    typedef decay<T189 [3]>::type         foo6_189;
    struct T190 { };
    typedef decay<T190>::type             foo1_190;
    typedef decay<T190&>::type            foo2_190;
    typedef decay<T190&&>::type           foo3_190;
    typedef decay<T190 const>::type       foo4_190;
    typedef decay<T190 volatile>::type    foo5_190;
    typedef decay<T190 [3]>::type         foo6_190;
    struct T191 { };
    typedef decay<T191>::type             foo1_191;
    typedef decay<T191&>::type            foo2_191;
    typedef decay<T191&&>::type           foo3_191;
    typedef decay<T191 const>::type       foo4_191;
    typedef decay<T191 volatile>::type    foo5_191;
    typedef decay<T191 [3]>::type         foo6_191;
    struct T192 { };
    typedef decay<T192>::type             foo1_192;
    typedef decay<T192&>::type            foo2_192;
    typedef decay<T192&&>::type           foo3_192;
    typedef decay<T192 const>::type       foo4_192;
    typedef decay<T192 volatile>::type    foo5_192;
    typedef decay<T192 [3]>::type         foo6_192;
    struct T193 { };
    typedef decay<T193>::type             foo1_193;
    typedef decay<T193&>::type            foo2_193;
    typedef decay<T193&&>::type           foo3_193;
    typedef decay<T193 const>::type       foo4_193;
    typedef decay<T193 volatile>::type    foo5_193;
    typedef decay<T193 [3]>::type         foo6_193;
    struct T194 { };
    typedef decay<T194>::type             foo1_194;
    typedef decay<T194&>::type            foo2_194;
    typedef decay<T194&&>::type           foo3_194;
    typedef decay<T194 const>::type       foo4_194;
    typedef decay<T194 volatile>::type    foo5_194;
    typedef decay<T194 [3]>::type         foo6_194;
    struct T195 { };
    typedef decay<T195>::type             foo1_195;
    typedef decay<T195&>::type            foo2_195;
    typedef decay<T195&&>::type           foo3_195;
    typedef decay<T195 const>::type       foo4_195;
    typedef decay<T195 volatile>::type    foo5_195;
    typedef decay<T195 [3]>::type         foo6_195;
    struct T196 { };
    typedef decay<T196>::type             foo1_196;
    typedef decay<T196&>::type            foo2_196;
    typedef decay<T196&&>::type           foo3_196;
    typedef decay<T196 const>::type       foo4_196;
    typedef decay<T196 volatile>::type    foo5_196;
    typedef decay<T196 [3]>::type         foo6_196;
    struct T197 { };
    typedef decay<T197>::type             foo1_197;
    typedef decay<T197&>::type            foo2_197;
    typedef decay<T197&&>::type           foo3_197;
    typedef decay<T197 const>::type       foo4_197;
    typedef decay<T197 volatile>::type    foo5_197;
    typedef decay<T197 [3]>::type         foo6_197;
    struct T198 { };
    typedef decay<T198>::type             foo1_198;
    typedef decay<T198&>::type            foo2_198;
    typedef decay<T198&&>::type           foo3_198;
    typedef decay<T198 const>::type       foo4_198;
    typedef decay<T198 volatile>::type    foo5_198;
    typedef decay<T198 [3]>::type         foo6_198;
    struct T199 { };
    typedef decay<T199>::type             foo1_199;
    typedef decay<T199&>::type            foo2_199;
    typedef decay<T199&&>::type           foo3_199;
    typedef decay<T199 const>::type       foo4_199;
    typedef decay<T199 volatile>::type    foo5_199;
    typedef decay<T199 [3]>::type         foo6_199;

#endif

int main() { }
